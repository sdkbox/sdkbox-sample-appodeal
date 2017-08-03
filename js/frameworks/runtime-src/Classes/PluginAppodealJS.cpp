#include "PluginAppodealJS.hpp"
#include "PluginAppodeal/PluginAppodeal.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 52
#elif MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS_ReportErrorUTF8(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginAppodeal_class;
#if MOZJS_MAJOR_VERSION < 33
JSObject *jsb_sdkbox_PluginAppodeal_prototype;
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, args.get(0), (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible : Error processing arguments");
        sdkbox::PluginAppodeal::setBannerBackgroundVisible(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, argv[0], (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setBannerBackgroundVisible(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled : Error processing arguments");
        bool ret = sdkbox::PluginAppodeal::isAutocacheEnabled(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginAppodeal::isAutocacheEnabled(arg0);
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_hideBanner(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginAppodeal::hideBanner();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_hideBanner : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_hideBanner(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginAppodeal::hideBanner();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserGender(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Gender arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserGender : Error processing arguments");
        sdkbox::PluginAppodeal::setUserGender(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserGender : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserGender(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Gender arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserGender(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, args.get(0), (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled : Error processing arguments");
        sdkbox::PluginAppodeal::setBannerAnimationEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, argv[0], (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setBannerAnimationEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_getSDKVersion(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginAppodeal::getSDKVersion();
        JS::RootedValue jsret(cx);
        sdkbox::c_string_to_jsval(cx, ret.c_str(), &jsret, ret.size());
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_getSDKVersion : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginAppodeal::getSDKVersion();
        jsval jsret;
        sdkbox::c_string_to_jsval(cx, ret.c_str(), &jsret, ret.size());
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        sdkbox::PluginAppodeal::AdType arg0;
        std::string arg1;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType : Error processing arguments");
        sdkbox::PluginAppodeal::disableNetworkForAdType(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        sdkbox::PluginAppodeal::AdType arg0;
        std::string arg1;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::disableNetworkForAdType(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::SmokingAttitude arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude : Error processing arguments");
        sdkbox::PluginAppodeal::setUserSmokingAttitude(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::SmokingAttitude arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserSmokingAttitude(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserInterests(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserInterests : Error processing arguments");
        sdkbox::PluginAppodeal::setUserInterests(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserInterests : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserInterests(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserInterests(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserBirthday(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserBirthday : Error processing arguments");
        sdkbox::PluginAppodeal::setUserBirthday(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserBirthday : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserBirthday(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserBirthday(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, args.get(0), (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled : Error processing arguments");
        sdkbox::PluginAppodeal::setSmartBannersEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, argv[0], (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setSmartBannersEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginAppodeal::disableLocationPermissionCheck();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginAppodeal::disableLocationPermissionCheck();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AlcoholAttitude arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude : Error processing arguments");
        sdkbox::PluginAppodeal::setUserAlcoholAttitude(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AlcoholAttitude arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserAlcoholAttitude(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserOccupation(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Occupation arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserOccupation : Error processing arguments");
        sdkbox::PluginAppodeal::setUserOccupation(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserOccupation : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserOccupation(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Occupation arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserOccupation(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::ShowStyle arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle : Error processing arguments");
        bool ret = sdkbox::PluginAppodeal::isReadyForShowWithStyle(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::ShowStyle arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginAppodeal::isReadyForShowWithStyle(arg0);
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserVkId(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserVkId : Error processing arguments");
        sdkbox::PluginAppodeal::setUserVkId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserVkId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserVkId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserVkId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_cacheAd(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_cacheAd : Error processing arguments");
        sdkbox::PluginAppodeal::cacheAd(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_cacheAd : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_cacheAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::cacheAd(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setAutocache(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        bool arg0;
        sdkbox::PluginAppodeal::AdType arg1;
        ok &= sdkbox::js_to_bool(cx, args.get(0), (bool *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setAutocache : Error processing arguments");
        sdkbox::PluginAppodeal::setAutocache(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setAutocache : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setAutocache(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        bool arg0;
        sdkbox::PluginAppodeal::AdType arg1;
        ok &= sdkbox::js_to_bool(cx, argv[0], (bool *)&arg0);
        ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setAutocache(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setDebugEnabled(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, args.get(0), (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setDebugEnabled : Error processing arguments");
        sdkbox::PluginAppodeal::setDebugEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setDebugEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setDebugEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, argv[0], (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setDebugEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserAge(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserAge : Error processing arguments");
        sdkbox::PluginAppodeal::setUserAge(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserAge : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserAge(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserAge(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_init(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 0) {
        bool ret = sdkbox::PluginAppodeal::init();
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_init : Error processing arguments");
        bool ret = sdkbox::PluginAppodeal::init(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 0) {
        bool ret = sdkbox::PluginAppodeal::init();
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginAppodeal::init(arg0);
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserEmail(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserEmail : Error processing arguments");
        sdkbox::PluginAppodeal::setUserEmail(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserEmail : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserEmail(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserEmail(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_confirmUsage(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_confirmUsage : Error processing arguments");
        sdkbox::PluginAppodeal::confirmUsage(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_confirmUsage : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_confirmUsage(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::confirmUsage(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserFacebookId(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserFacebookId : Error processing arguments");
        sdkbox::PluginAppodeal::setUserFacebookId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserFacebookId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserFacebookId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserFacebookId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserRelationship(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Relationship arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_setUserRelationship : Error processing arguments");
        sdkbox::PluginAppodeal::setUserRelationship(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_setUserRelationship : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserRelationship(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Relationship arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppodeal::setUserRelationship(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_showAd(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::ShowStyle arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppodealJS_PluginAppodeal_showAd : Error processing arguments");
        bool ret = sdkbox::PluginAppodeal::showAd(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppodealJS_PluginAppodeal_showAd : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_showAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginAppodeal::ShowStyle arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginAppodeal::showAd(arg0);
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginAppodealJS_PluginAppodeal_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginAppodeal)", obj);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAppodealJS_PluginAppodeal(JSContext *cx, JS::HandleObject global) {
    static JSClass PluginAgeCheq_class = {
        "PluginAppodeal",
        JSCLASS_HAS_PRIVATE,
        nullptr
    };
    jsb_sdkbox_PluginAppodeal_class = &PluginAgeCheq_class;

#if MOZJS_MAJOR_VERSION < 52
    jsb_sdkbox_PluginAppodeal_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppodeal_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginAppodeal_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppodeal_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAppodeal_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAppodeal_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAppodeal_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAppodeal_class->finalize = js_PluginAppodealJS_PluginAppodeal_finalize;
    jsb_sdkbox_PluginAppodeal_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
#endif

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setBannerBackgroundVisible", js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAutocacheEnabled", js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hideBanner", js_PluginAppodealJS_PluginAppodeal_hideBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserGender", js_PluginAppodealJS_PluginAppodeal_setUserGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerAnimationEnabled", js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSDKVersion", js_PluginAppodealJS_PluginAppodeal_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableNetworkForAdType", js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserSmokingAttitude", js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserInterests", js_PluginAppodealJS_PluginAppodeal_setUserInterests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserBirthday", js_PluginAppodealJS_PluginAppodeal_setUserBirthday, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSmartBannersEnabled", js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableLocationPermissionCheck", js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserAlcoholAttitude", js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserOccupation", js_PluginAppodealJS_PluginAppodeal_setUserOccupation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isReadyForShowWithStyle", js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserVkId", js_PluginAppodealJS_PluginAppodeal_setUserVkId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheAd", js_PluginAppodealJS_PluginAppodeal_cacheAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAutocache", js_PluginAppodealJS_PluginAppodeal_setAutocache, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugEnabled", js_PluginAppodealJS_PluginAppodeal_setDebugEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserAge", js_PluginAppodealJS_PluginAppodeal_setUserAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAppodealJS_PluginAppodeal_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserEmail", js_PluginAppodealJS_PluginAppodeal_setUserEmail, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("confirmUsage", js_PluginAppodealJS_PluginAppodeal_confirmUsage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserFacebookId", js_PluginAppodealJS_PluginAppodeal_setUserFacebookId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserRelationship", js_PluginAppodealJS_PluginAppodeal_setUserRelationship, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAd", js_PluginAppodealJS_PluginAppodeal_showAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, nullptr);
    JSObject* objProto = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_sdkbox_PluginAppodeal_class,
        dummy_constructor<sdkbox::PluginAppodeal>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, objProto);
#if (SDKBOX_COCOS_JSB_VERSION >= 2)
#if MOZJS_MAJOR_VERSION >= 52
    jsb_register_class<sdkbox::PluginAppodeal>(cx, jsb_sdkbox_PluginAppodeal_class, proto);
#else
    jsb_register_class<sdkbox::PluginAppodeal>(cx, jsb_sdkbox_PluginAppodeal_class, proto, JS::NullPtr());
#endif
#else
    TypeTest<sdkbox::PluginAppodeal> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginAppodeal_class;
        p->proto = objProto;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif

    // add the proto and JSClass to the type->js info hash table
    JS::RootedValue className(cx);
    JSString* jsstr = JS_NewStringCopyZ(cx, "PluginAppodeal");
    className = JS::StringValue(jsstr);
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
}
#else
void js_register_PluginAppodealJS_PluginAppodeal(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginAppodeal_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginAppodeal_class->name = "PluginAppodeal";
    jsb_sdkbox_PluginAppodeal_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppodeal_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginAppodeal_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppodeal_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAppodeal_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAppodeal_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAppodeal_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAppodeal_class->finalize = js_PluginAppodealJS_PluginAppodeal_finalize;
    jsb_sdkbox_PluginAppodeal_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setBannerBackgroundVisible", js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAutocacheEnabled", js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hideBanner", js_PluginAppodealJS_PluginAppodeal_hideBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserGender", js_PluginAppodealJS_PluginAppodeal_setUserGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerAnimationEnabled", js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSDKVersion", js_PluginAppodealJS_PluginAppodeal_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableNetworkForAdType", js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserSmokingAttitude", js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserInterests", js_PluginAppodealJS_PluginAppodeal_setUserInterests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserBirthday", js_PluginAppodealJS_PluginAppodeal_setUserBirthday, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSmartBannersEnabled", js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableLocationPermissionCheck", js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserAlcoholAttitude", js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserOccupation", js_PluginAppodealJS_PluginAppodeal_setUserOccupation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isReadyForShowWithStyle", js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserVkId", js_PluginAppodealJS_PluginAppodeal_setUserVkId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheAd", js_PluginAppodealJS_PluginAppodeal_cacheAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAutocache", js_PluginAppodealJS_PluginAppodeal_setAutocache, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugEnabled", js_PluginAppodealJS_PluginAppodeal_setDebugEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserAge", js_PluginAppodealJS_PluginAppodeal_setUserAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAppodealJS_PluginAppodeal_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserEmail", js_PluginAppodealJS_PluginAppodeal_setUserEmail, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("confirmUsage", js_PluginAppodealJS_PluginAppodeal_confirmUsage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserFacebookId", js_PluginAppodealJS_PluginAppodeal_setUserFacebookId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserRelationship", js_PluginAppodealJS_PluginAppodeal_setUserRelationship, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAd", js_PluginAppodealJS_PluginAppodeal_showAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginAppodeal_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginAppodeal_class,
        dummy_constructor<sdkbox::PluginAppodeal>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginAppodeal", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginAppodeal> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginAppodeal_class;
        p->proto = jsb_sdkbox_PluginAppodeal_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginAppodealJS_PluginAppodeal(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginAppodeal_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginAppodeal_class->name = "PluginAppodeal";
    jsb_sdkbox_PluginAppodeal_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppodeal_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppodeal_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppodeal_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAppodeal_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAppodeal_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAppodeal_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAppodeal_class->finalize = js_PluginAppodealJS_PluginAppodeal_finalize;
    jsb_sdkbox_PluginAppodeal_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setBannerBackgroundVisible", js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAutocacheEnabled", js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hideBanner", js_PluginAppodealJS_PluginAppodeal_hideBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserGender", js_PluginAppodealJS_PluginAppodeal_setUserGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerAnimationEnabled", js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSDKVersion", js_PluginAppodealJS_PluginAppodeal_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableNetworkForAdType", js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserSmokingAttitude", js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserInterests", js_PluginAppodealJS_PluginAppodeal_setUserInterests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserBirthday", js_PluginAppodealJS_PluginAppodeal_setUserBirthday, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSmartBannersEnabled", js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableLocationPermissionCheck", js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserAlcoholAttitude", js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserOccupation", js_PluginAppodealJS_PluginAppodeal_setUserOccupation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isReadyForShowWithStyle", js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserVkId", js_PluginAppodealJS_PluginAppodeal_setUserVkId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheAd", js_PluginAppodealJS_PluginAppodeal_cacheAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAutocache", js_PluginAppodealJS_PluginAppodeal_setAutocache, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugEnabled", js_PluginAppodealJS_PluginAppodeal_setDebugEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserAge", js_PluginAppodealJS_PluginAppodeal_setUserAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAppodealJS_PluginAppodeal_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserEmail", js_PluginAppodealJS_PluginAppodeal_setUserEmail, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("confirmUsage", js_PluginAppodealJS_PluginAppodeal_confirmUsage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserFacebookId", js_PluginAppodealJS_PluginAppodeal_setUserFacebookId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserRelationship", js_PluginAppodealJS_PluginAppodeal_setUserRelationship, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAd", js_PluginAppodealJS_PluginAppodeal_showAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginAppodeal_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginAppodeal_class,
        dummy_constructor<sdkbox::PluginAppodeal>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginAppodeal", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginAppodeal> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginAppodeal_class;
        p->proto = jsb_sdkbox_PluginAppodeal_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginAppodealJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginAppodealJS_PluginAppodeal(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginAppodealJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginAppodealJS_PluginAppodeal(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginAppodealJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginAppodealJS_PluginAppodeal(cx, obj);

    sdkbox::setProjectType("js");
}
#endif