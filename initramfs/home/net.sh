#!/bin/sh
echo "Loading wireless modules..."
insmod /lib/modules/cfg80211.ko || echo "Failed to load cfg80211"
insmod /lib/modules/mac80211.ko || echo "Failed to load mac80211"
insmod /lib/modules/iwlwifi.ko || echo "Failed to load iwlwifi"

echo "Modules loaded."
