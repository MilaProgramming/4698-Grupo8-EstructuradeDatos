// Examples.cpp
#undef ASPOSE_PDF_UNIT_TEST
#undef ASPOSE_PDF_SHARED_EXPORTS

#include "stdafx.h"

using namespace System;
using namespace Aspose::Document;


using namespace Aspose::TextFragment;

void Example1()
{
    auto doc = MakeObject<Document>();
    auto pages = doc->get_Pages();
    pages->Add();
    //Numeration of Pages starts from 1
    auto page = pages->idx_get(1);
    auto paragraps = page->get_Paragraphs();
    
    paragraps->Add(MakeObject<TextFragment>(u"Hello World!"));
    
    auto text = MakeObject<TextFragment>(u"This example is created by Aspose.Pdf for C++.");
    auto ts = text->get_TextState();

    ts->set_FontSize(16);
    ts->set_FontStyle(FontStyles::Italic);
    paragraps->Add(text);

    doc->Save(u"Example1.pdf");
    Console::WriteLine(u"Example1 finished.");
}