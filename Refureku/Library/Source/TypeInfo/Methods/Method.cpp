#include "TypeInfo/Methods/Method.h"

#include "TypeInfo/Struct.h"

using namespace refureku;

Method::Method(std::string&& methodName, uint64 methodId, EAccessSpecifier accessSpecifier, Struct const* methodOwnerType, std::shared_ptr<ICallable>&& internalMethod) noexcept:
	MethodBase(std::forward<std::string>(methodName), std::forward<uint64>(methodId), std::forward<EAccessSpecifier>(accessSpecifier), std::forward<std::shared_ptr<ICallable>>(internalMethod)),
	ownerType{methodOwnerType}
{}