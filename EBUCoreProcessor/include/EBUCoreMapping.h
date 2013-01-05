
#include <libMXF++/MXF.h>

//#include "EBU_CORE_20110915.hxx"
//#include "EBU_CORE_20120403.hxx"
#include "EBU_CORE_20120817.hxx"

#include <MXFCustomMetadata.h>
#include <metadata/EBUCoreDMS++.h>

using namespace EBUSDK::MXFCustomMetadata;
using namespace EBUSDK::EBUCore::KLV;

namespace EBUSDK {
namespace EBUCore {

void mapCoreMetadata(ebuCore_2012::coreMetadataType& source, ebucoreCoreMetadata *dest, mxfRational overallFrameRate, std::vector<ebucorePartMetadata*>& timelineParts, ObjectModifier* mod = NULL);
void mapCoreMetadata(ebucoreCoreMetadata *source, ebuCore_2012::coreMetadataType& dest);
void mapMetadataSchemeInformation(ebuCore_2012::ebuCoreMainType& source, ebucoreMetadataSchemeInformation *dest, ObjectModifier* mod = NULL);
void mapMetadataSchemeInformation(ebucoreMetadataSchemeInformation *source, ebuCore_2012::ebuCoreMainType& dest);
void mapEntity(ebuCore_2012::entityType& source, ebucoreEntity *dest, ObjectModifier* mod = NULL);
void mapEntity(ebucoreEntity *source, ebuCore_2012::entityType& dest);

}
}