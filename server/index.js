const preferences = require("./preferences");
const mouse = require("./build/Release/device");

const express = require('express');
var app = express();

app.get("/mouse", (req, res, next) => {
  if(req.query.down) {
    console.log("down");
    mouse.emit(mouse.EV_KEY, mouse.BTN_LEFT, 1);
  }
  if(req.query.up) {
    console.log("up");
    mouse.emit(mouse.EV_KEY, mouse.BTN_LEFT, 0);
  }
  if(req.query.updownup) {
    console.log("updownup");
    mouse.emit(mouse.EV_KEY, mouse.BTN_LEFT, 0);
    setTimeout(() => mouse.emit(mouse.EV_KEY, mouse.BTN_LEFT, 1), 50);
    setTimeout(() => mouse.emit(mouse.EV_KEY, mouse.BTN_LEFT, 0), 100);
  }
  if(req.query.move) {
    console.log("move");
    mouse.emit(mouse.EV_REL, mouse.REL_X, req.query.moveX);
    mouse.emit(mouse.EV_REL, mouse.REL_Y, req.query.moveY);
  }
  res.json({
    "success": true
  });
});

app.listen(preferences.port, preferences.addr);
