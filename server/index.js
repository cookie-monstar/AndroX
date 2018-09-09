const http = require("http");
const url = require("url");
const env = require("./preferences");
const xorg= require("./build/Release/xorg");

http.createServer((req, res) => {
  let query = url.parse(req.url, true);
  if(query.mousedown) xdo.mousedown();
  if(query.mouseup) xdo.mouseup();
  if(query.move) xdo.move(query.move);
  res.writeHead(200, {"Content-Type": "text/json"});
  res.end(JSON.stringify({
    "success": true
  }));
}).listen(env.port, env.addr);
