
# How to run sdkbox appodeal samples

Steps:

~~~bash
mkdir samples
cd samples

# must clone this repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-cocos2d-x-binary.git

# clone sample repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-sample-appodeal.git

# run sample with specified language and platform
# eg: cpp and ios
## or
cd cpp && cocos run -p ios

./sdkbox-cocos2d-x-binary/run_sample.sh appodeal cpp ios
# javascript and android
## or
cd js && cocos run -p android

./sdkbox-cocos2d-x-binary/run_sample.sh appodeal js android

# run "download-depends.sh" in sample repo
./sdkbox-sample-appodeal/download-depends.sh

~~~

Memo:

1.  Sample repo and cocos2dx repo must be in same level directory

~~~
+-- sdkbox-cocos2d-x-binary
+-- sdkbox-sample-appodeal
| +-- cpp
| +-- lua
| \-- js
~~~



## Cpp Android Studio



1. cd cpp && cocos compile -p android
2. open Android Studio and import cpp project
3. run in Android Studio

