// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__301769E5_38DE_4C61_961D_F6060A0EAD40__INCLUDED_)
#define AFX_FACE_H__301769E5_38DE_4C61_961D_F6060A0EAD40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFace  
{
public:
	CFace();
	virtual ~CFace();
	void SetNum(int);  //设置面的定点数
public:
	int vN;  //面的顶点数
	int* vI;  //面的顶点索引

};

#endif // !defined(AFX_FACE_H__301769E5_38DE_4C61_961D_F6060A0EAD40__INCLUDED_)
