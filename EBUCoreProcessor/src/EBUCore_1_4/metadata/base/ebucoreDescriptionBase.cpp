 /*
  *    Copyright 2012-2013 European Broadcasting Union and Limecraft, NV.
  *
  *    Licensed under the Apache License, Version 2.0 (the "License");
  *    you may not use this file except in compliance with the License.
  *    You may obtain a copy of the License at
  *
  *       http://www.apache.org/licenses/LICENSE-2.0
  *
  *    Unless required by applicable law or agreed to in writing, software
  *    distributed under the License is distributed on an "AS IS" BASIS,
  *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  *    See the License for the specific language governing permissions and
  *    limitations under the License.
  *
  */
  
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <memory>

#include <libMXF++/MXF.h>
#include <EBUCore_1_4/metadata/EBUCoreDMS++.h>


using namespace std;
using namespace mxfpp;
using namespace EBUSDK::EBUCore::EBUCore_1_4::KLV;


const mxfKey ebucoreDescriptionBase::setKey = MXF_SET_K(ebucoreDescription);


ebucoreDescriptionBase::ebucoreDescriptionBase(HeaderMetadata *headerMetadata)
: InterchangeObject(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

ebucoreDescriptionBase::ebucoreDescriptionBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: InterchangeObject(headerMetadata, cMetadataSet)
{}

ebucoreDescriptionBase::~ebucoreDescriptionBase()
{}


bool ebucoreDescriptionBase::havedescriptionNote() const
{
    return haveItem(&MXF_ITEM_K(ebucoreDescription, descriptionNote));
}

std::string ebucoreDescriptionBase::getdescriptionNote() const
{
    return getStringItem(&MXF_ITEM_K(ebucoreDescription, descriptionNote));
}

bool ebucoreDescriptionBase::havedescriptionValue() const
{
    return haveItem(&MXF_ITEM_K(ebucoreDescription, descriptionValue));
}

std::vector<ebucoreTextualAnnotation*> ebucoreDescriptionBase::getdescriptionValue() const
{
    vector<ebucoreTextualAnnotation*> result;
    auto_ptr<ObjectIterator> iter(getStrongRefArrayItem(&MXF_ITEM_K(ebucoreDescription, descriptionValue)));
    while (iter->next())
    {
        MXFPP_CHECK(dynamic_cast<ebucoreTextualAnnotation*>(iter->get()) != 0);
        result.push_back(dynamic_cast<ebucoreTextualAnnotation*>(iter->get()));
    }
    return result;
}

bool ebucoreDescriptionBase::havedescriptionTypeGroup() const
{
    return haveItem(&MXF_ITEM_K(ebucoreDescription, descriptionTypeGroup));
}

ebucoreTypeGroup* ebucoreDescriptionBase::getdescriptionTypeGroup() const
{
    auto_ptr<MetadataSet> obj(getStrongRefItem(&MXF_ITEM_K(ebucoreDescription, descriptionTypeGroup)));
    MXFPP_CHECK(dynamic_cast<ebucoreTypeGroup*>(obj.get()) != 0);
    return dynamic_cast<ebucoreTypeGroup*>(obj.release());
}

void ebucoreDescriptionBase::setdescriptionNote(std::string value)
{
    setStringItem(&MXF_ITEM_K(ebucoreDescription, descriptionNote), value);
}

void ebucoreDescriptionBase::setdescriptionValue(const std::vector<ebucoreTextualAnnotation*>& value)
{
    WrapObjectVectorIterator<ebucoreTextualAnnotation> iter(value);
    setStrongRefArrayItem(&MXF_ITEM_K(ebucoreDescription, descriptionValue), &iter);
}

void ebucoreDescriptionBase::appenddescriptionValue(ebucoreTextualAnnotation* value)
{
    appendStrongRefArrayItem(&MXF_ITEM_K(ebucoreDescription, descriptionValue), value);
}

void ebucoreDescriptionBase::setdescriptionTypeGroup(ebucoreTypeGroup* value)
{
    setStrongRefItem(&MXF_ITEM_K(ebucoreDescription, descriptionTypeGroup), value);
}

