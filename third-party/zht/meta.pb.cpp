// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: meta.proto

#include "meta.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

class PackageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Package> _instance;
} _Package_default_instance_;
static void InitDefaultsPackage_meta_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Package_default_instance_;
    new (ptr) ::Package();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Package::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Package_meta_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsPackage_meta_2eproto}, {}};

void InitDefaults_meta_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_Package_meta_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_meta_2eproto[1];
constexpr ::google::protobuf::EnumDescriptor const** file_level_enum_descriptors_meta_2eproto = nullptr;
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_meta_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_meta_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::Package, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::Package, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Package, virtualpath_),
  PROTOBUF_FIELD_OFFSET(::Package, realfullpath_),
  PROTOBUF_FIELD_OFFSET(::Package, isdir_),
  PROTOBUF_FIELD_OFFSET(::Package, replicanum_),
  PROTOBUF_FIELD_OFFSET(::Package, listitem_),
  0,
  1,
  2,
  3,
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::Package)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_Package_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_meta_2eproto = {
  {}, AddDescriptors_meta_2eproto, "meta.proto", schemas,
  file_default_instances, TableStruct_meta_2eproto::offsets,
  file_level_metadata_meta_2eproto, 1, file_level_enum_descriptors_meta_2eproto, file_level_service_descriptors_meta_2eproto,
};

::google::protobuf::internal::DescriptorTable descriptor_table_meta_2eproto = {
  false, InitDefaults_meta_2eproto, 
  "\n\nmeta.proto\"i\n\007Package\022\023\n\013virtualPath\030\001"
  " \001(\t\022\024\n\014realFullPath\030\002 \001(\t\022\r\n\005isDir\030\003 \001("
  "\010\022\022\n\nreplicanum\030\004 \001(\005\022\020\n\010listItem\030\005 \003(\t"
,
  "meta.proto", &assign_descriptors_table_meta_2eproto, 119,
};

void AddDescriptors_meta_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_meta_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_meta_2eproto = []() { AddDescriptors_meta_2eproto(); return true; }();

// ===================================================================

void Package::InitAsDefaultInstance() {
}
class Package::HasBitSetters {
 public:
  static void set_has_virtualpath(Package* msg) {
    msg->_has_bits_[0] |= 0x00000001u;
  }
  static void set_has_realfullpath(Package* msg) {
    msg->_has_bits_[0] |= 0x00000002u;
  }
  static void set_has_isdir(Package* msg) {
    msg->_has_bits_[0] |= 0x00000004u;
  }
  static void set_has_replicanum(Package* msg) {
    msg->_has_bits_[0] |= 0x00000008u;
  }
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Package::kVirtualPathFieldNumber;
const int Package::kRealFullPathFieldNumber;
const int Package::kIsDirFieldNumber;
const int Package::kReplicanumFieldNumber;
const int Package::kListItemFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Package::Package()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Package)
}
Package::Package(const Package& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      listitem_(from.listitem_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  virtualpath_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_virtualpath()) {
    virtualpath_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.virtualpath_);
  }
  realfullpath_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_realfullpath()) {
    realfullpath_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.realfullpath_);
  }
  ::memcpy(&isdir_, &from.isdir_,
    static_cast<size_t>(reinterpret_cast<char*>(&replicanum_) -
    reinterpret_cast<char*>(&isdir_)) + sizeof(replicanum_));
  // @@protoc_insertion_point(copy_constructor:Package)
}

void Package::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_Package_meta_2eproto.base);
  virtualpath_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  realfullpath_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&isdir_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&replicanum_) -
      reinterpret_cast<char*>(&isdir_)) + sizeof(replicanum_));
}

Package::~Package() {
  // @@protoc_insertion_point(destructor:Package)
  SharedDtor();
}

void Package::SharedDtor() {
  virtualpath_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  realfullpath_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Package::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Package& Package::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_Package_meta_2eproto.base);
  return *internal_default_instance();
}


void Package::Clear() {
// @@protoc_insertion_point(message_clear_start:Package)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  listitem_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      virtualpath_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      realfullpath_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 0x0000000cu) {
    ::memset(&isdir_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&replicanum_) -
        reinterpret_cast<char*>(&isdir_)) + sizeof(replicanum_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* Package::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<Package*>(object);
  ::google::protobuf::uint32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ::google::protobuf::uint32 tag;
    ptr = Varint::Parse32Inline(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // optional string virtualPath = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = Varint::Parse32Inline(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("Package.virtualPath");
        parser_till_end = ::google::protobuf::internal::StringParserUTF8Verify;
        ::std::string* str = msg->mutable_virtualpath();
        str->clear();
        object = str;
        if (size > end - ptr) goto len_delim_till_end;
        auto newend = ptr + size;
        if (size) ptr = parser_till_end(ptr, newend, object, ctx);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr == newend);
        break;
      }
      // optional string realFullPath = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) != 18) goto handle_unusual;
        ptr = Varint::Parse32Inline(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("Package.realFullPath");
        parser_till_end = ::google::protobuf::internal::StringParserUTF8Verify;
        ::std::string* str = msg->mutable_realfullpath();
        str->clear();
        object = str;
        if (size > end - ptr) goto len_delim_till_end;
        auto newend = ptr + size;
        if (size) ptr = parser_till_end(ptr, newend, object, ctx);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr == newend);
        break;
      }
      // optional bool isDir = 3;
      case 3: {
        if (static_cast<::google::protobuf::uint8>(tag) != 24) goto handle_unusual;
        ::google::protobuf::uint64 val;
        ptr = Varint::Parse64(ptr, &val);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        bool value = val;
        msg->set_isdir(value);
        break;
      }
      // optional int32 replicanum = 4;
      case 4: {
        if (static_cast<::google::protobuf::uint8>(tag) != 32) goto handle_unusual;
        ::google::protobuf::uint64 val;
        ptr = Varint::Parse64(ptr, &val);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ::google::protobuf::int32 value = val;
        msg->set_replicanum(value);
        break;
      }
      // repeated string listItem = 5;
      case 5: {
        if (static_cast<::google::protobuf::uint8>(tag) != 42) goto handle_unusual;
        do {
          ptr = Varint::Parse32Inline(ptr, &size);
          GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
          ctx->extra_parse_data().SetFieldName("Package.listItem");
          parser_till_end = ::google::protobuf::internal::StringParserUTF8Verify;
          ::std::string* str = msg->add_listitem();
          str->clear();
          object = str;
          if (size > end - ptr) goto len_delim_till_end;
          auto newend = ptr + size;
          if (size) ptr = parser_till_end(ptr, newend, object, ctx);
          GOOGLE_PROTOBUF_PARSER_ASSERT(ptr == newend);
          if (ptr >= end) break;
        } while ((::google::protobuf::io::UnalignedLoad<::google::protobuf::uint64>(ptr) & 255) == 42 && (ptr += 1));
        break;
      }
      default: {
      handle_unusual: (void)&&handle_unusual;
        if ((tag & 7) == 4 || tag == 0) {
          bool ok = ctx->ValidEndGroup(tag);
          GOOGLE_PROTOBUF_PARSER_ASSERT(ok);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
len_delim_till_end: (void)&&len_delim_till_end;
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                                 {parser_till_end, object}, size);
group_continues: (void)&&group_continues;
  GOOGLE_DCHECK(ptr >= end);
  ctx->StoreGroup({_InternalParse, msg}, {parser_till_end, object}, depth);
  return ptr;
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool Package::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Package)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string virtualPath = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_virtualpath()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->virtualpath().data(), static_cast<int>(this->virtualpath().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Package.virtualPath");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string realFullPath = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (18 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_realfullpath()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->realfullpath().data(), static_cast<int>(this->realfullpath().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Package.realFullPath");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool isDir = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (24 & 0xFF)) {
          HasBitSetters::set_has_isdir(this);
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &isdir_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 replicanum = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (32 & 0xFF)) {
          HasBitSetters::set_has_replicanum(this);
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &replicanum_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated string listItem = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (42 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_listitem()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->listitem(this->listitem_size() - 1).data(),
            static_cast<int>(this->listitem(this->listitem_size() - 1).length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Package.listItem");
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Package)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Package)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void Package::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Package)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string virtualPath = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->virtualpath().data(), static_cast<int>(this->virtualpath().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Package.virtualPath");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->virtualpath(), output);
  }

  // optional string realFullPath = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->realfullpath().data(), static_cast<int>(this->realfullpath().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Package.realFullPath");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->realfullpath(), output);
  }

  // optional bool isDir = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->isdir(), output);
  }

  // optional int32 replicanum = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->replicanum(), output);
  }

  // repeated string listItem = 5;
  for (int i = 0, n = this->listitem_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->listitem(i).data(), static_cast<int>(this->listitem(i).length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Package.listItem");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->listitem(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Package)
}

::google::protobuf::uint8* Package::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Package)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string virtualPath = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->virtualpath().data(), static_cast<int>(this->virtualpath().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Package.virtualPath");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->virtualpath(), target);
  }

  // optional string realFullPath = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->realfullpath().data(), static_cast<int>(this->realfullpath().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Package.realFullPath");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->realfullpath(), target);
  }

  // optional bool isDir = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->isdir(), target);
  }

  // optional int32 replicanum = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->replicanum(), target);
  }

  // repeated string listItem = 5;
  for (int i = 0, n = this->listitem_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->listitem(i).data(), static_cast<int>(this->listitem(i).length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Package.listItem");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(5, this->listitem(i), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Package)
  return target;
}

size_t Package::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Package)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string listItem = 5;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->listitem_size());
  for (int i = 0, n = this->listitem_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->listitem(i));
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    // optional string virtualPath = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->virtualpath());
    }

    // optional string realFullPath = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->realfullpath());
    }

    // optional bool isDir = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 + 1;
    }

    // optional int32 replicanum = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->replicanum());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Package::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Package)
  GOOGLE_DCHECK_NE(&from, this);
  const Package* source =
      ::google::protobuf::DynamicCastToGenerated<Package>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Package)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Package)
    MergeFrom(*source);
  }
}

void Package::MergeFrom(const Package& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Package)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  listitem_.MergeFrom(from.listitem_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      virtualpath_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.virtualpath_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      realfullpath_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.realfullpath_);
    }
    if (cached_has_bits & 0x00000004u) {
      isdir_ = from.isdir_;
    }
    if (cached_has_bits & 0x00000008u) {
      replicanum_ = from.replicanum_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Package::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Package)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Package::CopyFrom(const Package& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Package)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Package::IsInitialized() const {
  return true;
}

void Package::Swap(Package* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Package::InternalSwap(Package* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  listitem_.InternalSwap(CastToBase(&other->listitem_));
  virtualpath_.Swap(&other->virtualpath_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  realfullpath_.Swap(&other->realfullpath_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(isdir_, other->isdir_);
  swap(replicanum_, other->replicanum_);
}

::google::protobuf::Metadata Package::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_meta_2eproto);
  return ::file_level_metadata_meta_2eproto[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> PROTOBUF_NOINLINE ::Package* Arena::CreateMaybeMessage< ::Package >(Arena* arena) {
  return Arena::CreateInternal< ::Package >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
