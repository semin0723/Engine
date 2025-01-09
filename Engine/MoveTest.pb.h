// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: MoveTest.proto
// Protobuf C++ Version: 5.28.3

#ifndef GOOGLE_PROTOBUF_INCLUDED_MoveTest_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_MoveTest_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5028003
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_MoveTest_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_MoveTest_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_MoveTest_2eproto;
namespace MoveTest {
class AsyncPlayer;
struct AsyncPlayerDefaultTypeInternal;
extern AsyncPlayerDefaultTypeInternal _AsyncPlayer_default_instance_;
class Move;
struct MoveDefaultTypeInternal;
extern MoveDefaultTypeInternal _Move_default_instance_;
class PlayerEnter;
struct PlayerEnterDefaultTypeInternal;
extern PlayerEnterDefaultTypeInternal _PlayerEnter_default_instance_;
}  // namespace MoveTest
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace MoveTest {

// ===================================================================


// -------------------------------------------------------------------

class PlayerEnter final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:MoveTest.PlayerEnter) */ {
 public:
  inline PlayerEnter() : PlayerEnter(nullptr) {}
  ~PlayerEnter() PROTOBUF_FINAL;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR PlayerEnter(
      ::google::protobuf::internal::ConstantInitialized);

  inline PlayerEnter(const PlayerEnter& from) : PlayerEnter(nullptr, from) {}
  inline PlayerEnter(PlayerEnter&& from) noexcept
      : PlayerEnter(nullptr, std::move(from)) {}
  inline PlayerEnter& operator=(const PlayerEnter& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerEnter& operator=(PlayerEnter&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PlayerEnter& default_instance() {
    return *internal_default_instance();
  }
  static inline const PlayerEnter* internal_default_instance() {
    return reinterpret_cast<const PlayerEnter*>(
        &_PlayerEnter_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(PlayerEnter& a, PlayerEnter& b) { a.Swap(&b); }
  inline void Swap(PlayerEnter* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerEnter* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PlayerEnter* New(::google::protobuf::Arena* arena = nullptr) const PROTOBUF_FINAL {
    return ::google::protobuf::Message::DefaultConstruct<PlayerEnter>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const PlayerEnter& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const PlayerEnter& from) { PlayerEnter::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(PlayerEnter* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "MoveTest.PlayerEnter"; }

 protected:
  explicit PlayerEnter(::google::protobuf::Arena* arena);
  PlayerEnter(::google::protobuf::Arena* arena, const PlayerEnter& from);
  PlayerEnter(::google::protobuf::Arena* arena, PlayerEnter&& from) noexcept
      : PlayerEnter(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const PROTOBUF_FINAL;
  static const ::google::protobuf::Message::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kObjnumFieldNumber = 1,
    kObjverFieldNumber = 2,
  };
  // optional uint64 objnum = 1;
  bool has_objnum() const;
  void clear_objnum() ;
  ::uint64_t objnum() const;
  void set_objnum(::uint64_t value);

  private:
  ::uint64_t _internal_objnum() const;
  void _internal_set_objnum(::uint64_t value);

  public:
  // optional uint64 objver = 2;
  bool has_objver() const;
  void clear_objver() ;
  ::uint64_t objver() const;
  void set_objver(::uint64_t value);

  private:
  ::uint64_t _internal_objver() const;
  void _internal_set_objver(::uint64_t value);

  public:
  // @@protoc_insertion_point(class_scope:MoveTest.PlayerEnter)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      0, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_PlayerEnter_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const PlayerEnter& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::uint64_t objnum_;
    ::uint64_t objver_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_MoveTest_2eproto;
};
// -------------------------------------------------------------------

class Move final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:MoveTest.Move) */ {
 public:
  inline Move() : Move(nullptr) {}
  ~Move() PROTOBUF_FINAL;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Move(
      ::google::protobuf::internal::ConstantInitialized);

  inline Move(const Move& from) : Move(nullptr, from) {}
  inline Move(Move&& from) noexcept
      : Move(nullptr, std::move(from)) {}
  inline Move& operator=(const Move& from) {
    CopyFrom(from);
    return *this;
  }
  inline Move& operator=(Move&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Move& default_instance() {
    return *internal_default_instance();
  }
  static inline const Move* internal_default_instance() {
    return reinterpret_cast<const Move*>(
        &_Move_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(Move& a, Move& b) { a.Swap(&b); }
  inline void Swap(Move* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Move* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Move* New(::google::protobuf::Arena* arena = nullptr) const PROTOBUF_FINAL {
    return ::google::protobuf::Message::DefaultConstruct<Move>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Move& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Move& from) { Move::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Move* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "MoveTest.Move"; }

 protected:
  explicit Move(::google::protobuf::Arena* arena);
  Move(::google::protobuf::Arena* arena, const Move& from);
  Move(::google::protobuf::Arena* arena, Move&& from) noexcept
      : Move(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const PROTOBUF_FINAL;
  static const ::google::protobuf::Message::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kObjnumFieldNumber = 1,
    kObjverFieldNumber = 2,
    kXFieldNumber = 3,
    kYFieldNumber = 4,
    kDeltaFieldNumber = 6,
    kSpeedFieldNumber = 5,
  };
  // optional uint64 objnum = 1;
  bool has_objnum() const;
  void clear_objnum() ;
  ::uint64_t objnum() const;
  void set_objnum(::uint64_t value);

  private:
  ::uint64_t _internal_objnum() const;
  void _internal_set_objnum(::uint64_t value);

  public:
  // optional uint64 objver = 2;
  bool has_objver() const;
  void clear_objver() ;
  ::uint64_t objver() const;
  void set_objver(::uint64_t value);

  private:
  ::uint64_t _internal_objver() const;
  void _internal_set_objver(::uint64_t value);

  public:
  // optional float x = 3;
  bool has_x() const;
  void clear_x() ;
  float x() const;
  void set_x(float value);

  private:
  float _internal_x() const;
  void _internal_set_x(float value);

  public:
  // optional float y = 4;
  bool has_y() const;
  void clear_y() ;
  float y() const;
  void set_y(float value);

  private:
  float _internal_y() const;
  void _internal_set_y(float value);

  public:
  // optional double delta = 6;
  bool has_delta() const;
  void clear_delta() ;
  double delta() const;
  void set_delta(double value);

  private:
  double _internal_delta() const;
  void _internal_set_delta(double value);

  public:
  // optional float speed = 5;
  bool has_speed() const;
  void clear_speed() ;
  float speed() const;
  void set_speed(float value);

  private:
  float _internal_speed() const;
  void _internal_set_speed(float value);

  public:
  // @@protoc_insertion_point(class_scope:MoveTest.Move)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 6, 0,
      0, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_Move_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Move& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::uint64_t objnum_;
    ::uint64_t objver_;
    float x_;
    float y_;
    double delta_;
    float speed_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_MoveTest_2eproto;
};
// -------------------------------------------------------------------

class AsyncPlayer final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:MoveTest.AsyncPlayer) */ {
 public:
  inline AsyncPlayer() : AsyncPlayer(nullptr) {}
  ~AsyncPlayer() PROTOBUF_FINAL;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR AsyncPlayer(
      ::google::protobuf::internal::ConstantInitialized);

  inline AsyncPlayer(const AsyncPlayer& from) : AsyncPlayer(nullptr, from) {}
  inline AsyncPlayer(AsyncPlayer&& from) noexcept
      : AsyncPlayer(nullptr, std::move(from)) {}
  inline AsyncPlayer& operator=(const AsyncPlayer& from) {
    CopyFrom(from);
    return *this;
  }
  inline AsyncPlayer& operator=(AsyncPlayer&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const AsyncPlayer& default_instance() {
    return *internal_default_instance();
  }
  static inline const AsyncPlayer* internal_default_instance() {
    return reinterpret_cast<const AsyncPlayer*>(
        &_AsyncPlayer_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 2;
  friend void swap(AsyncPlayer& a, AsyncPlayer& b) { a.Swap(&b); }
  inline void Swap(AsyncPlayer* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(AsyncPlayer* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  AsyncPlayer* New(::google::protobuf::Arena* arena = nullptr) const PROTOBUF_FINAL {
    return ::google::protobuf::Message::DefaultConstruct<AsyncPlayer>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const AsyncPlayer& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const AsyncPlayer& from) { AsyncPlayer::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(AsyncPlayer* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "MoveTest.AsyncPlayer"; }

 protected:
  explicit AsyncPlayer(::google::protobuf::Arena* arena);
  AsyncPlayer(::google::protobuf::Arena* arena, const AsyncPlayer& from);
  AsyncPlayer(::google::protobuf::Arena* arena, AsyncPlayer&& from) noexcept
      : AsyncPlayer(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const PROTOBUF_FINAL;
  static const ::google::protobuf::Message::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kObjnumFieldNumber = 1,
    kObjverFieldNumber = 2,
    kXFieldNumber = 3,
    kYFieldNumber = 4,
  };
  // optional uint64 objnum = 1;
  bool has_objnum() const;
  void clear_objnum() ;
  ::uint64_t objnum() const;
  void set_objnum(::uint64_t value);

  private:
  ::uint64_t _internal_objnum() const;
  void _internal_set_objnum(::uint64_t value);

  public:
  // optional uint64 objver = 2;
  bool has_objver() const;
  void clear_objver() ;
  ::uint64_t objver() const;
  void set_objver(::uint64_t value);

  private:
  ::uint64_t _internal_objver() const;
  void _internal_set_objver(::uint64_t value);

  public:
  // optional float x = 3;
  bool has_x() const;
  void clear_x() ;
  float x() const;
  void set_x(float value);

  private:
  float _internal_x() const;
  void _internal_set_x(float value);

  public:
  // optional float y = 4;
  bool has_y() const;
  void clear_y() ;
  float y() const;
  void set_y(float value);

  private:
  float _internal_y() const;
  void _internal_set_y(float value);

  public:
  // @@protoc_insertion_point(class_scope:MoveTest.AsyncPlayer)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 4, 0,
      0, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_AsyncPlayer_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const AsyncPlayer& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::uint64_t objnum_;
    ::uint64_t objver_;
    float x_;
    float y_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_MoveTest_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// PlayerEnter

// optional uint64 objnum = 1;
inline bool PlayerEnter::has_objnum() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void PlayerEnter::clear_objnum() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objnum_ = ::uint64_t{0u};
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::uint64_t PlayerEnter::objnum() const {
  // @@protoc_insertion_point(field_get:MoveTest.PlayerEnter.objnum)
  return _internal_objnum();
}
inline void PlayerEnter::set_objnum(::uint64_t value) {
  _internal_set_objnum(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:MoveTest.PlayerEnter.objnum)
}
inline ::uint64_t PlayerEnter::_internal_objnum() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.objnum_;
}
inline void PlayerEnter::_internal_set_objnum(::uint64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objnum_ = value;
}

// optional uint64 objver = 2;
inline bool PlayerEnter::has_objver() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void PlayerEnter::clear_objver() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objver_ = ::uint64_t{0u};
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::uint64_t PlayerEnter::objver() const {
  // @@protoc_insertion_point(field_get:MoveTest.PlayerEnter.objver)
  return _internal_objver();
}
inline void PlayerEnter::set_objver(::uint64_t value) {
  _internal_set_objver(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:MoveTest.PlayerEnter.objver)
}
inline ::uint64_t PlayerEnter::_internal_objver() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.objver_;
}
inline void PlayerEnter::_internal_set_objver(::uint64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objver_ = value;
}

// -------------------------------------------------------------------

// Move

// optional uint64 objnum = 1;
inline bool Move::has_objnum() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Move::clear_objnum() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objnum_ = ::uint64_t{0u};
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::uint64_t Move::objnum() const {
  // @@protoc_insertion_point(field_get:MoveTest.Move.objnum)
  return _internal_objnum();
}
inline void Move::set_objnum(::uint64_t value) {
  _internal_set_objnum(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:MoveTest.Move.objnum)
}
inline ::uint64_t Move::_internal_objnum() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.objnum_;
}
inline void Move::_internal_set_objnum(::uint64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objnum_ = value;
}

// optional uint64 objver = 2;
inline bool Move::has_objver() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void Move::clear_objver() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objver_ = ::uint64_t{0u};
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::uint64_t Move::objver() const {
  // @@protoc_insertion_point(field_get:MoveTest.Move.objver)
  return _internal_objver();
}
inline void Move::set_objver(::uint64_t value) {
  _internal_set_objver(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:MoveTest.Move.objver)
}
inline ::uint64_t Move::_internal_objver() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.objver_;
}
inline void Move::_internal_set_objver(::uint64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objver_ = value;
}

// optional float x = 3;
inline bool Move::has_x() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void Move::clear_x() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.x_ = 0;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline float Move::x() const {
  // @@protoc_insertion_point(field_get:MoveTest.Move.x)
  return _internal_x();
}
inline void Move::set_x(float value) {
  _internal_set_x(value);
  _impl_._has_bits_[0] |= 0x00000004u;
  // @@protoc_insertion_point(field_set:MoveTest.Move.x)
}
inline float Move::_internal_x() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.x_;
}
inline void Move::_internal_set_x(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.x_ = value;
}

// optional float y = 4;
inline bool Move::has_y() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void Move::clear_y() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.y_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline float Move::y() const {
  // @@protoc_insertion_point(field_get:MoveTest.Move.y)
  return _internal_y();
}
inline void Move::set_y(float value) {
  _internal_set_y(value);
  _impl_._has_bits_[0] |= 0x00000008u;
  // @@protoc_insertion_point(field_set:MoveTest.Move.y)
}
inline float Move::_internal_y() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.y_;
}
inline void Move::_internal_set_y(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.y_ = value;
}

// optional float speed = 5;
inline bool Move::has_speed() const {
  bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline void Move::clear_speed() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.speed_ = 0;
  _impl_._has_bits_[0] &= ~0x00000020u;
}
inline float Move::speed() const {
  // @@protoc_insertion_point(field_get:MoveTest.Move.speed)
  return _internal_speed();
}
inline void Move::set_speed(float value) {
  _internal_set_speed(value);
  _impl_._has_bits_[0] |= 0x00000020u;
  // @@protoc_insertion_point(field_set:MoveTest.Move.speed)
}
inline float Move::_internal_speed() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.speed_;
}
inline void Move::_internal_set_speed(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.speed_ = value;
}

// optional double delta = 6;
inline bool Move::has_delta() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline void Move::clear_delta() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.delta_ = 0;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline double Move::delta() const {
  // @@protoc_insertion_point(field_get:MoveTest.Move.delta)
  return _internal_delta();
}
inline void Move::set_delta(double value) {
  _internal_set_delta(value);
  _impl_._has_bits_[0] |= 0x00000010u;
  // @@protoc_insertion_point(field_set:MoveTest.Move.delta)
}
inline double Move::_internal_delta() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.delta_;
}
inline void Move::_internal_set_delta(double value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.delta_ = value;
}

// -------------------------------------------------------------------

// AsyncPlayer

// optional uint64 objnum = 1;
inline bool AsyncPlayer::has_objnum() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void AsyncPlayer::clear_objnum() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objnum_ = ::uint64_t{0u};
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::uint64_t AsyncPlayer::objnum() const {
  // @@protoc_insertion_point(field_get:MoveTest.AsyncPlayer.objnum)
  return _internal_objnum();
}
inline void AsyncPlayer::set_objnum(::uint64_t value) {
  _internal_set_objnum(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:MoveTest.AsyncPlayer.objnum)
}
inline ::uint64_t AsyncPlayer::_internal_objnum() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.objnum_;
}
inline void AsyncPlayer::_internal_set_objnum(::uint64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objnum_ = value;
}

// optional uint64 objver = 2;
inline bool AsyncPlayer::has_objver() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void AsyncPlayer::clear_objver() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objver_ = ::uint64_t{0u};
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::uint64_t AsyncPlayer::objver() const {
  // @@protoc_insertion_point(field_get:MoveTest.AsyncPlayer.objver)
  return _internal_objver();
}
inline void AsyncPlayer::set_objver(::uint64_t value) {
  _internal_set_objver(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:MoveTest.AsyncPlayer.objver)
}
inline ::uint64_t AsyncPlayer::_internal_objver() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.objver_;
}
inline void AsyncPlayer::_internal_set_objver(::uint64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.objver_ = value;
}

// optional float x = 3;
inline bool AsyncPlayer::has_x() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void AsyncPlayer::clear_x() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.x_ = 0;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline float AsyncPlayer::x() const {
  // @@protoc_insertion_point(field_get:MoveTest.AsyncPlayer.x)
  return _internal_x();
}
inline void AsyncPlayer::set_x(float value) {
  _internal_set_x(value);
  _impl_._has_bits_[0] |= 0x00000004u;
  // @@protoc_insertion_point(field_set:MoveTest.AsyncPlayer.x)
}
inline float AsyncPlayer::_internal_x() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.x_;
}
inline void AsyncPlayer::_internal_set_x(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.x_ = value;
}

// optional float y = 4;
inline bool AsyncPlayer::has_y() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void AsyncPlayer::clear_y() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.y_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline float AsyncPlayer::y() const {
  // @@protoc_insertion_point(field_get:MoveTest.AsyncPlayer.y)
  return _internal_y();
}
inline void AsyncPlayer::set_y(float value) {
  _internal_set_y(value);
  _impl_._has_bits_[0] |= 0x00000008u;
  // @@protoc_insertion_point(field_set:MoveTest.AsyncPlayer.y)
}
inline float AsyncPlayer::_internal_y() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.y_;
}
inline void AsyncPlayer::_internal_set_y(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.y_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace MoveTest


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_MoveTest_2eproto_2epb_2eh
