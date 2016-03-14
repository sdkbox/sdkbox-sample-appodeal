#include "PluginAppodealLua.hpp"
#include "PluginAppodeal/PluginAppodeal.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginAppodealLua_PluginAppodeal_isAutocacheEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:isAutocacheEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_isAutocacheEnabled'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAppodeal::isAutocacheEnabled(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:isAutocacheEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_isAutocacheEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_hideBanner(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_hideBanner'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::hideBanner();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:hideBanner",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_hideBanner'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserGender(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::Gender arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:setUserGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserGender'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserGender",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserGender'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_disableNetworkForAdType(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        sdkbox::PluginAppodeal::AdType arg0;
        std::string arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:disableNetworkForAdType");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginAppodeal:disableNetworkForAdType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_disableNetworkForAdType'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::disableNetworkForAdType(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:disableNetworkForAdType",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_disableNetworkForAdType'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserSmokingAttitude(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::SmokingAttitude arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:setUserSmokingAttitude");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserSmokingAttitude'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserSmokingAttitude(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserSmokingAttitude",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserSmokingAttitude'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserInterests(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppodeal:setUserInterests");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserInterests'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserInterests(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserInterests",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserInterests'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserBirthday(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppodeal:setUserBirthday");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserBirthday'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserBirthday(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserBirthday",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserBirthday'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAppodeal::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_disableLocationPermissionCheck(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_disableLocationPermissionCheck'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::disableLocationPermissionCheck();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:disableLocationPermissionCheck",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_disableLocationPermissionCheck'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserAlcoholAttitude(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::AlcoholAttitude arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:setUserAlcoholAttitude");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserAlcoholAttitude'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserAlcoholAttitude(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserAlcoholAttitude",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserAlcoholAttitude'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserOccupation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::Occupation arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:setUserOccupation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserOccupation'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserOccupation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserOccupation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserOccupation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_isReadyForShowWithStyle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::ShowStyle arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:isReadyForShowWithStyle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_isReadyForShowWithStyle'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAppodeal::isReadyForShowWithStyle(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:isReadyForShowWithStyle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_isReadyForShowWithStyle'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserVkId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppodeal:setUserVkId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserVkId'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserVkId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserVkId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserVkId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_cacheAd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:cacheAd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_cacheAd'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::cacheAd(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:cacheAd",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_cacheAd'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setAutocache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        bool arg0;
        sdkbox::PluginAppodeal::AdType arg1;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginAppodeal:setAutocache");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginAppodeal:setAutocache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setAutocache'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setAutocache(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setAutocache",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setAutocache'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setDebugEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginAppodeal:setDebugEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setDebugEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setDebugEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setDebugEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setDebugEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserAge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:setUserAge");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserAge'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserAge(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserAge",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserAge'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserEmail(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppodeal:setUserEmail");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserEmail'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserEmail(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserEmail",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserEmail'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_confirmUsage(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:confirmUsage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_confirmUsage'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::confirmUsage(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:confirmUsage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_confirmUsage'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserFacebookId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppodeal:setUserFacebookId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserFacebookId'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserFacebookId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserFacebookId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserFacebookId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_setUserRelationship(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::Relationship arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:setUserRelationship");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_setUserRelationship'", nullptr);
            return 0;
        }
        sdkbox::PluginAppodeal::setUserRelationship(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:setUserRelationship",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_setUserRelationship'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppodealLua_PluginAppodeal_showAd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppodeal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginAppodeal::ShowStyle arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginAppodeal:showAd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppodealLua_PluginAppodeal_showAd'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAppodeal::showAd(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppodeal:showAd",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppodealLua_PluginAppodeal_showAd'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginAppodealLua_PluginAppodeal_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginAppodeal)");
    return 0;
}

int lua_register_PluginAppodealLua_PluginAppodeal(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginAppodeal");
    tolua_cclass(tolua_S,"PluginAppodeal","sdkbox.PluginAppodeal","",nullptr);

    tolua_beginmodule(tolua_S,"PluginAppodeal");
        tolua_function(tolua_S,"isAutocacheEnabled", lua_PluginAppodealLua_PluginAppodeal_isAutocacheEnabled);
        tolua_function(tolua_S,"hideBanner", lua_PluginAppodealLua_PluginAppodeal_hideBanner);
        tolua_function(tolua_S,"setUserGender", lua_PluginAppodealLua_PluginAppodeal_setUserGender);
        tolua_function(tolua_S,"disableNetworkForAdType", lua_PluginAppodealLua_PluginAppodeal_disableNetworkForAdType);
        tolua_function(tolua_S,"setUserSmokingAttitude", lua_PluginAppodealLua_PluginAppodeal_setUserSmokingAttitude);
        tolua_function(tolua_S,"setUserInterests", lua_PluginAppodealLua_PluginAppodeal_setUserInterests);
        tolua_function(tolua_S,"setUserBirthday", lua_PluginAppodealLua_PluginAppodeal_setUserBirthday);
        tolua_function(tolua_S,"init", lua_PluginAppodealLua_PluginAppodeal_init);
        tolua_function(tolua_S,"disableLocationPermissionCheck", lua_PluginAppodealLua_PluginAppodeal_disableLocationPermissionCheck);
        tolua_function(tolua_S,"setUserAlcoholAttitude", lua_PluginAppodealLua_PluginAppodeal_setUserAlcoholAttitude);
        tolua_function(tolua_S,"setUserOccupation", lua_PluginAppodealLua_PluginAppodeal_setUserOccupation);
        tolua_function(tolua_S,"isReadyForShowWithStyle", lua_PluginAppodealLua_PluginAppodeal_isReadyForShowWithStyle);
        tolua_function(tolua_S,"setUserVkId", lua_PluginAppodealLua_PluginAppodeal_setUserVkId);
        tolua_function(tolua_S,"cacheAd", lua_PluginAppodealLua_PluginAppodeal_cacheAd);
        tolua_function(tolua_S,"setAutocache", lua_PluginAppodealLua_PluginAppodeal_setAutocache);
        tolua_function(tolua_S,"setDebugEnabled", lua_PluginAppodealLua_PluginAppodeal_setDebugEnabled);
        tolua_function(tolua_S,"setUserAge", lua_PluginAppodealLua_PluginAppodeal_setUserAge);
        tolua_function(tolua_S,"setUserEmail", lua_PluginAppodealLua_PluginAppodeal_setUserEmail);
        tolua_function(tolua_S,"confirmUsage", lua_PluginAppodealLua_PluginAppodeal_confirmUsage);
        tolua_function(tolua_S,"setUserFacebookId", lua_PluginAppodealLua_PluginAppodeal_setUserFacebookId);
        tolua_function(tolua_S,"setUserRelationship", lua_PluginAppodealLua_PluginAppodeal_setUserRelationship);
        tolua_function(tolua_S,"showAd", lua_PluginAppodealLua_PluginAppodeal_showAd);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginAppodeal).name();
    g_luaType[typeName] = "sdkbox.PluginAppodeal";
    g_typeCast["PluginAppodeal"] = "sdkbox.PluginAppodeal";
    return 1;
}
TOLUA_API int register_all_PluginAppodealLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginAppodealLua_PluginAppodeal(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

