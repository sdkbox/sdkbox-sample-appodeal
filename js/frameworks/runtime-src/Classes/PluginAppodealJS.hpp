#ifndef __PluginAppodealJS_h__
#define __PluginAppodealJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAppodealJS_PluginAppodeal(JSContext *cx, JS::HandleObject global);
void register_all_PluginAppodealJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginAppodealJS_PluginAppodeal(JSContext *cx, JSObject* global);
void register_all_PluginAppodealJS(JSContext* cx, JSObject* obj);
#endif
#endif

