#!/bin/bash
CUR_DIR=$(cd "$(dirname $0)" && pwd)

cd $CUR_DIR

MD5="MD5 (Appodeal.zip) = a8ca3fb004c3b895e76e5ae43aa68bcc"
ZIP_FILENAME="Appodeal.zip"
TMP_DIR="__tmp"

if [ -f $ZIP_FILENAME ]; then
	# check zip
	CHECK_MD5=`md5 $ZIP_FILENAME`
	echo $CHECK_MD5, $MD5
	if [ "$CHECK_MD5" != "$MD5" ]; then
		echo rm $ZIP_FILENAME
		rm $ZIP_FILENAME
	fi
fi

if [ ! -f $ZIP_FILENAME ]; then
	curl -o $ZIP_FILENAME "https://s3-us-west-1.amazonaws.com/appodeal-ios/0.8.1/Appodeal.zip"
fi

if [ -d $TMP_DIR ]; then
	rm -fr $TMP_DIR
fi

mkdir $TMP_DIR
cd $TMP_DIR
unzip ../$ZIP_FILENAME

cp -R Appodeal.framework ../cpp/proj.ios_mac/
cp -R Appodeal.framework ../lua/frameworks/runtime-src/proj.ios_mac/
cp -R Appodeal.framework ../js/frameworks/runtime-src/proj.ios_mac/

cd ..
rm -fr $TMP_DIR

echo "DONE."
