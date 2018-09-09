const preferences = require("./preferences");
const xorg= require("./build/Release/xorg");

const express = require('express');
var app = express();

app.get("/mouse", (req, res, next) => {
  if(req.query.down) xorg.mousedown();
  if(req.query.up) xorg.mouseup();
  if(req.query.move) xorg.mousemove(req.query.moveX, req.query.moveY);
  res.json({
    "success": true
  });
  //console.log(req.query.info);
});

app.listen(preferences.port, preferences.addr);
