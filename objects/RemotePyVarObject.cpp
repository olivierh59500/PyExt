#include "RemotePyVarObject.h"

#include "utils/ExtHelpers.h"

#include <engextcpp.hpp>

#include <string>
using namespace std;

RemotePyVarObject::RemotePyVarObject(Offset objectAddress, const string& typeName /*= "PyVarObject"*/)
	: RemotePyObject(objectAddress, typeName)
{
}


auto RemotePyVarObject::size() const -> SSize
{
	auto sizeField = remoteObj().Field("ob_size");
	return readIntegral<SSize>(sizeField);
}
