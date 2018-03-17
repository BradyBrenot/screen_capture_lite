#pragma once
#include "SCCommon.h"
#include <DXGI.h>
#include <memory>
#include <wrl.h>

#include <d3d11.h>
#include <dxgi1_2.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

namespace SL {
namespace Screen_Capture {
    class DXFrameProcessor : public BaseFrameProcessor {
        Microsoft::WRL::ComPtr<ID3D11Device> Device;
        Microsoft::WRL::ComPtr<ID3D11DeviceContext> DeviceContext;
        
        Microsoft::WRL::ComPtr<ID3D11Texture2D> FullFrame;
        Microsoft::WRL::ComPtr<ID3D11Texture2D> StagingSurf;
        Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> ShaderResource;

        Microsoft::WRL::ComPtr<IDXGIOutputDuplication> OutputDuplication;
        DXGI_OUTPUT_DESC OutputDesc;
        UINT Output;
        std::vector<BYTE> MetaDataBuffer;
        Monitor SelectedMonitor;

      public:
        DUPL_RETURN Init(std::shared_ptr<Thread_Data> data, Monitor &monitor);
        DUPL_RETURN ProcessFrame(const Monitor &currentmonitorinfo);
    };

} // namespace Screen_Capture
} // namespace SL