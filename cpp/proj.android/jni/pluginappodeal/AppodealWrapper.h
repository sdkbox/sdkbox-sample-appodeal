
#ifndef _PLUGIN_APPODEAL_WRAPPER_H_
#define _PLUGIN_APPODEAL_WRAPPER_H_

#include "PluginAppodeal.h"
#include "CocosMacros.h"

#define TAG     "Appodeal"
#define VERSION "0.10.0"

NS_COCOS_BEGIN

class AppodealWrapper {
public:
    static AppodealWrapper* getInstance();
    
    virtual bool init()=0;
    virtual bool __init( bool, const void* )=0;
    
    virtual void setListener(AppodealListener* listener)=0;
    virtual AppodealListener* getListener()=0;
    virtual void removeListener()=0;
    
    virtual std::string getSDKVersion()=0;
    virtual void disableNetworkForAdType(PluginAppodeal::AdType adType, const std::string& networkName)=0;
    virtual void disableLocationPermissionCheck()=0;
    virtual void setAutocache(bool autocache, PluginAppodeal::AdType types)=0;
    virtual bool isAutocacheEnabled(PluginAppodeal::AdType types)=0;
    virtual void confirmUsage(PluginAppodeal::AdType adTypes)=0;
    
    virtual void setDebugEnabled(bool debugEnabled)=0;
    virtual bool showAd(PluginAppodeal::ShowStyle style)=0;
    virtual void cacheAd(PluginAppodeal::AdType type)=0;
    virtual void hideBanner()=0;
    virtual bool isReadyForShowWithStyle(PluginAppodeal::ShowStyle showStyle)=0;
    
    virtual void setUserVkId(const std::string& vkId)=0;
    virtual void setUserFacebookId(const std::string& facebookId)=0;
    virtual void setUserEmail(const std::string& email)=0;
    virtual void setUserBirthday(const std::string& birthday)=0;
    virtual void setUserAge(int age)=0;
    virtual void setUserGender(PluginAppodeal::Gender gender)=0;
    virtual void setUserOccupation(PluginAppodeal::Occupation occupation)=0;
    virtual void setUserRelationship(PluginAppodeal::Relationship relationship)=0;
    virtual void setUserSmokingAttitude(PluginAppodeal::SmokingAttitude smokingAttitude)=0;
    virtual void setUserAlcoholAttitude(PluginAppodeal::AlcoholAttitude alcoholAttitude)=0;
    virtual void setUserInterests(const std::string& interests)=0;
};

class AppodealWrapperDisabled : public AppodealWrapper {
public:
    bool init() { return false; }
    bool __init( bool, const void* ) { return false; }
    
    void setListener(AppodealListener* listener) {}
    AppodealListener* getListener() { return NULL; }
    void removeListener() {}
    
    std::string getSDKVersion() { return ""; };
    void disableNetworkForAdType(PluginAppodeal::AdType adType, const std::string& networkName) {}
    void disableLocationPermissionCheck() {}
    void setAutocache(bool autocache, PluginAppodeal::AdType types) {}
    bool isAutocacheEnabled(PluginAppodeal::AdType types) { return false; }
    void confirmUsage(PluginAppodeal::AdType adTypes) {}
    
    void setDebugEnabled(bool debugEnabled) {}
    bool showAd(PluginAppodeal::ShowStyle style) { return false; }
    void cacheAd(PluginAppodeal::AdType type) {}
    void hideBanner() {}
    bool isReadyForShowWithStyle(PluginAppodeal::ShowStyle showStyle) { return false; }
    
    void setUserVkId(const std::string& vkId) {}
    void setUserFacebookId(const std::string& facebookId) {}
    void setUserEmail(const std::string& email) {}
    void setUserBirthday(const std::string& birthday) {}
    void setUserAge(int age) {}
    void setUserGender(PluginAppodeal::Gender gender) {}
    void setUserOccupation(PluginAppodeal::Occupation occupation) {}
    void setUserRelationship(PluginAppodeal::Relationship relationship) {}
    void setUserSmokingAttitude(PluginAppodeal::SmokingAttitude smokingAttitude) {}
    void setUserAlcoholAttitude(PluginAppodeal::AlcoholAttitude alcoholAttitude) {}
    void setUserInterests(const std::string& interests){}
};

class AppodealWrapperEnabled : public AppodealWrapper {
public:
    
    AppodealWrapperEnabled();
    
    bool init();
    bool __init( bool, const void* );
    
    void setListener(AppodealListener* listener);
    AppodealListener* getListener();
    void removeListener();

    std::string getSDKVersion();
    void disableNetworkForAdType(PluginAppodeal::AdType adType, const std::string& networkName);
    void disableLocationPermissionCheck();
    void setAutocache(bool autocache, PluginAppodeal::AdType types);
    bool isAutocacheEnabled(PluginAppodeal::AdType types);
    void confirmUsage(PluginAppodeal::AdType adTypes);

    void setDebugEnabled(bool debugEnabled);
    bool showAd(PluginAppodeal::ShowStyle style);
    void cacheAd(PluginAppodeal::AdType type);
    void hideBanner();
    bool isReadyForShowWithStyle(PluginAppodeal::ShowStyle showStyle);

    void setUserVkId(const std::string& vkId);
    void setUserFacebookId(const std::string& facebookId);
    void setUserEmail(const std::string& email);
    void setUserBirthday(const std::string& birthday);
    void setUserAge(int age);
    void setUserGender(PluginAppodeal::Gender gender);
    void setUserOccupation(PluginAppodeal::Occupation occupation);
    void setUserRelationship(PluginAppodeal::Relationship relationship);
    void setUserSmokingAttitude(PluginAppodeal::SmokingAttitude smokingAttitude);
    void setUserAlcoholAttitude(PluginAppodeal::AlcoholAttitude alcoholAttitude);
    void setUserInterests(const std::string& interests);

protected:
    std::string nativeSDKVersion();
    bool nativeInit(const std::string& appKey, bool asAdUnit, const void* unitPtr );

    AppodealListener* _listener = nullptr;
    std::string _appID = "";
    std::string _devKey = "";
};

NS_COCOS_END

#endif
