#ifndef __PluginAppodealJS_h__
#define __PluginAppodealJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginAppodeal_class;
extern JSObject *jsb_sdkbox_PluginAppodeal_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAppodealJS_PluginAppodeal(JSContext *cx, JS::HandleObject global);
void register_all_PluginAppodealJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginAppodealJS_PluginAppodeal(JSContext *cx, JSObject* global);
void register_all_PluginAppodealJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginAppodealJS_PluginAppodeal_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginAppodealJS_PluginAppodeal_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_hideBanner(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_hideBanner(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserGender(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserGender(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserInterests(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserInterests(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserBirthday(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserBirthday(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserOccupation(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserOccupation(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserVkId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserVkId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_cacheAd(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_cacheAd(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setAutocache(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setAutocache(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setDebugEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setDebugEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserAge(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserAge(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserEmail(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserEmail(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_confirmUsage(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_confirmUsage(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserFacebookId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserFacebookId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_setUserRelationship(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_setUserRelationship(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppodealJS_PluginAppodeal_showAd(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppodealJS_PluginAppodeal_showAd(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

