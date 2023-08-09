#pragma once

#include "Client_Defines.h"
#include "Character.h"

BEGIN(Engine)

END

BEGIN(Client)

class CMonster : public CCharacter
{
public:
	

protected:
	CMonster(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	CMonster(const CMonster& rhs);
	virtual ~CMonster() = default;

public:
	virtual HRESULT Initialize_Prototype();
	virtual HRESULT Initialize(void* pArg) override;
	virtual void	Tick(_double dTimeDelta) override;
	virtual void	LateTick(_double dTimeDelta) override;
	virtual HRESULT Render() override;
	virtual HRESULT Render_ShadowDepth();

public:
	void  Calculate_To_Player(_int Level);

protected:
	//플레이어 정보 calculate
	_float			m_fDistance_To_Player;
	_float4		m_PlayerPos;
	_float4		m_Dir_To_Monster;
	_float4		m_Dir_To_Player;
	_float4		m_Dir_To_Player_FixY;
	


protected: //애니메이션 제어용 함수들
	void	Dir_Setting(_bool Reverse);


protected: // 애니메이션 제어용 변수들
	_bool m_isDeath_Motion = { false };
	

protected:
	/* 임시 코드 */
	_uint	m_iNumAnim = { 0 };
	// 렌더 확인용
	_uint	m_iMeshNum = { 0 };

	
protected:
	// Outline Default
	_float	m_fOutlineThickness = 0.9f;
	// Outline Face
	_float	m_fOutlineFaceThickness = 0.3f;


protected:
	HRESULT Add_Components();
	HRESULT	SetUp_ShaderResources();

public:
	static CMonster* Create(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END