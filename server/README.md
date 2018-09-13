# AndroX Server
Works only for Xorg Servers.
## Setup
### Setting up /dev/uinput
Skip this if you are okay to run the whole script as sudo (I'm sure you won't)
Make a group call uinput, and add user to the group.
```bash
sudo addgroup uinput
sudo adduser $USER uinput
```
Now add these lines to `/etc/udev/rules.d/99-input.rules`
```
KERNEL="uinput",GROUP="uinput",MODE:="0660"
```
### Setting up node and building addons
```bash
# Global Dependencies #
sudo apt-get install nodejs npm
sudo npm install -g node-gyp
# Local Dependencies #
npm install
# Build #
node-gyp configure
node-gyp rebuild
```
## Preferences
Are present in `preferences.json`
```json
{
  "password": "password",
  "protocol": "http",
  "address": "192.168.0.1",
  "port": 3000
}
```
    The server does not listen for changes in `preferences.json`. For now, restart the server.
## Run
```bash
npm start
```
