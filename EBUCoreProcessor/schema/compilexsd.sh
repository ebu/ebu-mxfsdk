#!/bin/sh
xsdcxx -tree \
--include-regex "@(.+)@xsd/$1@" \
--include-regex "@(.*EBU_CORE.*)@EBUCore_1_4/xsd/$1@" \
--generate-serialization --root-element ebuCoreMain --namespace-map http://purl.org/dc/elements/1.1/=dc EBU_CORE_20130107.xsd simpledc20021212.xsd
mv -f EBU_CORE*.hxx ..\include\EBUCore_1_4\xsd
mv -f *.hxx ..\include\xsd
mv -f EBU_CORE*.cxx ..\src\EBUCore_1_4\xsd
mv -f *.cxx ..\src\xsd
