# AndroX Server
Works only for Xorg Servers.
## Setup
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
