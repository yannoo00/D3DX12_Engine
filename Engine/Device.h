#pragma once
class Device
{

public:
	void Init();

	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }


private:

	// com��ü�� ���λ����� �Ű澲���ʰ� ��ġ�� ��üó�� ���.
	// DX�� ���α׷��־�� �������� ���� ȣȯ���� �����ϰ� �ϴ� ���.
	ComPtr<ID3D12Debug>	_debugController;
	ComPtr<IDXGIFactory> _dxgi;
	ComPtr<ID3D12Device> _device;

};

