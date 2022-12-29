Introduction
============
 - 정의 : Libxml은 XML Read / Write를 위한 C언어 라이브러리
 - - XML 문서 해석
 - - Specific Elements로부터 문자열 추출
 - - Elements / Contents 추가
 - - Attribute를 Elements에 추가
 - - Attribute 값 추출

Data Types
==========
 - xmlChar : UTF-8로 인코딩된 character type. UTF-8이 아닐 경우, 반드시 UTF-8로 변환하여 사용
 - xmlDoc : 해석된 XML 문서가 트리 구조로 저장될 수 있도록 마련된 structure. xmlDocPtr은 xmlDoc의 ptr
 - xmlNode : 하나의 노드를 저장하기 위한 구조체. xmlNodePtr은 xmlNode의 ptr. xmlDoc의 Tree 구조를 탐색하는데 사용

```C
xmlDocPtr doc; // 해석된 문서를 가리킬 포인터
xmlNodePtr cur; // node를 가리킬 포인터

doc = xmlParseFile(docname); // docname의 문서(.xml)를 불러와 해석

if(doc == NULL){ // docname의 문서 정상 open 여부 확인
  fprintf(stderr, "Document not parsed successfully.\n");
  return;
}

cur = xmlDocGetRootElement(doc); // find root element

if(cur == NULL){ // docname에 내용이 있는지 여부 확인
  fprintf(stderr, "empoty document\n");
  xmlFreeDoc(doc);
  return;
}

if(xmlStrcmp(cur -> name, (const xmlChar *) "story")){ // root element의 name이 story인지 확인
  fprintf(stderr, "document of the wrong type, root node != story");
  xmlFreeDoc(doc);
  return;
}
```

