#include "PipeLineSetup.h"

class Object_BaseCamp
{
public:
	PipeLineSetup  PipeLineSetup;
	D3DVECTOR      m_vCenter;

public:

	SimpleVertex	m_VertexList[6];
	UINT		    m_icount_Vertexs;

public:
	T_CB_DATA		m_Constant_Data;


public:
	virtual bool	Init() { return true;}
	virtual bool	Frame(float fGameTimer, float fFps)	{return true;}
	virtual bool	PreRender(ID3D11DeviceContext* pContext)	{ PipeLineSetup.PreRender(pContext);	return true;}
	virtual bool	Render(ID3D11DeviceContext* pContext) { PipeLineSetup.Render(pContext); return true;}
	virtual bool	PostRender(ID3D11DeviceContext* pContext) { PipeLineSetup.PostRender(pContext); return true;}
	virtual bool	Release() { return true;}
public:
	Object_BaseCamp() {}
	virtual ~Object_BaseCamp() {}
};

