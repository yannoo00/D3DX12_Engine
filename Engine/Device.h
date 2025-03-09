#pragma once
class Device
{

public:
	void Init();

	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }


private:

	// com객체로 세부사항을 신경쓰지않고 장치를 객체처럼 사용.
	// DX의 프로그래밍언어 독립성과 하위 호환성을 가능하게 하는 기술.
	ComPtr<ID3D12Debug>	_debugController;
	ComPtr<IDXGIFactory> _dxgi;
	ComPtr<ID3D12Device> _device;

};

