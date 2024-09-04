#include "pch.h"
#include "RenderSystem.h"
#include "ResourceSystem.h"

void RenderSystem::SpriteRender(ID2D1HwndRenderTarget* target, EntityId eid)
{
	Transform*	tf	= componentManager->GetComponent<Transform>(eid);
	Sprite*		sp	= componentManager->GetComponent<Sprite>(eid);

	if (sp != nullptr) {
		// TODO: Add Camera and mul inverse matrix to transform
		target->SetTransform(tf->GetWorldTransform());

		SpriteIdSet spSet = ResourceSystem::GetInstance()->GetSpriteSet(sp->_spriteId)->GetSpriteIdSet();
		auto bitmap = ResourceSystem::GetInstance()->GetSprite(spSet[sp->_curAnimationIdx]);

		D2D1_RECT_F dest = { 0, 0, sp->_size.x, sp->_size.y };

		target->DrawBitmap(bitmap, dest);
	}

	ChildEntities childs = entityManager->GetEntity(eid)->GetChildEntityId();

	// orderLayer가 낮은 순으로 그림 -> orderLayer가 높으면 제일 앞에 있음.
	std::sort(childs.begin(), childs.end(), 
		[&](EntityId& left, EntityId& right) {
			ULL leftOrderLayer = componentManager->GetComponent<Sprite>(left)->GetOrderLayer();
			ULL rightOrderLayer = componentManager->GetComponent<Sprite>(right)->GetOrderLayer();
			return leftOrderLayer < rightOrderLayer;
		}
	);

	for (EntityId& child : childs) {
		SpriteRender(target, child);
	}
}

void RenderSystem::UIRender(ID2D1HwndRenderTarget* target, EntityId eid)
{
	// TODO: UIGroup의 sorting은 클릭 이벤트가 UI에 들어갈 때 레이어를 변경해주는 작업을 해준다.
	UISprite*		sp	= componentManager->GetComponent<UISprite>(eid);
	TextComponent*	tc	= componentManager->GetComponent<TextComponent>(eid);

	if (sp != nullptr) {
		UISpriteRender(target, eid);
	}
	else if (tc != nullptr) {
		TextRender(target, eid);
	}

	ChildEntities childs = entityManager->GetEntity(eid)->GetChildEntityId();

	for (EntityId& child : childs) {
		UIRender(target, child);
	}

}

void RenderSystem::UISpriteRender(ID2D1HwndRenderTarget* target, EntityId eid)
{
	UITransform*	uitf	= componentManager->GetComponent<UITransform>(eid);
	UISprite*		uisp	= componentManager->GetComponent<UISprite>(eid);
	

	target->SetTransform(uitf->GetScreenTransform());

	SpriteIdSet spSet = ResourceSystem::GetInstance()->GetSpriteSet(uisp->_spriteId)->GetSpriteIdSet();
	auto bitmap = ResourceSystem::GetInstance()->GetSprite(spSet[uisp->_curAnimationIdx]);

	D2D1_RECT_F dest = { 0, 0, uisp->_size.x, uisp->_size.y };

	target->DrawBitmap(bitmap, dest);
}

void RenderSystem::TextRender(ID2D1HwndRenderTarget* target, EntityId eid)
{
	UITransform*	uitf	= componentManager->GetComponent<UITransform>(eid);
	TextComponent*	tc		= componentManager->GetComponent<TextComponent>(eid);

	target->SetTransform(uitf->GetScreenTransform());

	target->DrawText(
		tc->GetText().c_str(),
		tc->GetText().size(),
		ResourceSystem::GetInstance()->GetTextFormat(tc->GetFont(), tc->GetFontSize(), tc->GetTextAlignment(), tc->GetParagraphAlignment()),
		D2D1::RectF(
			0, 0,
			tc->GetTextAreaSize().x, tc->GetTextAreaSize().y
		),
		ResourceSystem::GetInstance()->GetBrush(BLACK)
	);
}

