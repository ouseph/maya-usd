#ifndef __HDMAYA_LIGHT_ADAPTER_H__
#define __HDMAYA_LIGHT_ADAPTER_H__

#include <pxr/pxr.h>

#include <pxr/base/gf/frustum.h>

#include <pxr/imaging/glf/simpleLight.h>
#include <pxr/imaging/hdx/simpleLightTask.h>

#include <maya/MFnLight.h>

#include <hdmaya/adapters/dagAdapter.h>

PXR_NAMESPACE_OPEN_SCOPE

class HdMayaLightAdapter : public HdMayaDagAdapter {
public:
    HDMAYA_API
    HdMayaLightAdapter(HdMayaDelegateCtx* delegate, const MDagPath& dag);
    HDMAYA_API
    virtual ~HdMayaLightAdapter() = default;
    HDMAYA_API
    void MarkDirty(HdDirtyBits dirtyBits) override;
    HDMAYA_API
    virtual void RemovePrim() override;
    HDMAYA_API
    VtValue GetLightParamValue(const TfToken& paramName) override;
    HDMAYA_API
    VtValue Get(const TfToken& key) override;
    HDMAYA_API
    virtual void CreateCallbacks() override;
    HDMAYA_API
    virtual void Populate() override;
protected:
    HDMAYA_API
    virtual void CalculateLightParams(GlfSimpleLight& light);
    HDMAYA_API
    void CalculateShadowParams(MFnLight& light, GfFrustum& frustum, HdxShadowParams& params);
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif // __HDMAYA_LIGHT_ADAPTER_H__
