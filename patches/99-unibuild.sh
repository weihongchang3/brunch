ret=0
if [ -f /system/usr/share/chromeos-config/config.json ]; then
	release=$(fgrep 'CHROMEOS_RELEASE_DESCRIPTION' /system/etc/lsb-release)
	board=$(echo $release | grep -oE "[^ ]+$")
	smbios=$(grep '"smbios-name-match": ' /system/usr/share/chromeos-config/config.json | sed -e 's/"smbios-name-match": //g' | tr -d " " | tr -d "," | tr -d \" | tr a-z A-Z | sort | uniq -c | sort -nr | awk '{print $2}' | head -n 1)
	if [ "$board" == "" ] || [ "$smbios" == "" ]; then ret=$((ret + (2 ** 0))); fi
	cat >/system/usr/share/chromeos-config/config.json <<CONFIG
{
  "chromeos": {
    "configs": [
      {
        "arc": {
          "build-properties": {
            "device": "${board}_cheets",
            "metrics-tag": "brunch",
            "product": "${board}"
          }
        },
        "brand-code": "TBD",
        "camera": {
          "count": 2
        },
        "hardware-properties": {
          "has-base-accelerometer": true,
          "has-base-gyroscope": true,
          "has-base-light-sensor": true,
          "has-base-magnetometer": true,
          "has-lid-accelerometer": true,
          "has-lid-gyroscope": true,
          "has-lid-light-sensor": true,
          "has-lid-magnetometer": true,
          "has-touchscreen": true,
          "is-lid-convertible": true,
          "stylus-category": "internal"
        },
        "identity": {
          "platform-name": "${board}",
          "smbios-name-match": "Brunch"
        },
        "name": "brunch",
        "test-label": "brunch"
      }
    ]
  }
}
CONFIG
	if [ ! "$?" -eq 0 ]; then ret=$((ret + (2 ** 1))); fi
	cat >/system/etc/init/hwid.conf <<HWID
start on starting boot-services

script
	echo "${smbios}" > /sys/devices/platform/chromeos_acpi/HWID
end script
HWID
	if [ ! "$?" -eq 0 ]; then ret=$((ret + (2 ** 2))); fi
fi
exit $ret
