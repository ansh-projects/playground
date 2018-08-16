var c = document.getElementById("gameboard");
var ctx = c.getContext("2d");
var leftPressed = false;
var rightPressed = false;
var upPressed = false;
var downPressed = false;
var score;
var snekHead = {
    x: 225,
    y: 225,
    h: 25,
    w: 25,
    s: 25
};
ctx.fillStyle="#585a5e";
ctx.fillRect(0,0,500,500);
ctx.strokeStyle="gray";

for(var i = 25; i < ctx.width; i = i + 25){
  ctx.moveTo(i, 0);
  ctx.lineTo(i, ctx.width);
  ctx.stroke();
}
for(var i = 25; i < ctx.height; i = i + 25){
  ctx.moveTo(0, i);
  ctx.lineTo(ctx.height, i);
  ctx.stroke();
}

document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);

function keyDownHandler(e) {
    if (e.keyCode == 37) {
        leftPressed = true;
        upPressed = false;
        rightPressed = false;
        downPressed = false;
        console.log("left");
    } else if (e.keyCode == 38) {
        leftPressed = false;
        upPressed = true;
        rightPressed = false;
        downPressed = false;
        console.log("up");
    } else if (e.keyCode == 39) {
        leftPressed = false;
        upPressed = false;
        rightPressed = true;
        downPressed = false;
        console.log("right");
    } else if (e.keyCode == 40) {
        leftPressed = false;
        upPressed = false;
        rightPressed = false;
        downPressed = true;
        console.log("down");
    }
}

function keyUpHandler(e) {
    if (e.keyCode == 37) {
        leftPressed = false;
    } else if (e.keyCode == 38) {
        upPressed = false;
    } else if (e.keyCode == 39) {
        rightPressed = false;
    } else if (e.keyCode == 40) {
        downPressed = false;
    }
}

function drawFood() {
    ctx.beginPath();
    ctx.rect(food.x, food.y, food.w, food.h);
    ctx.fillStyle = "HotPink";
    ctx.fill();
    ctx.closePath;
}

function drawSnek() {
    ctx.beginPath();
    ctx.rect(snekHead.x, snekHead.y, snekHead.w, snekHead.h);
    ctx.fillStyle = "white";
    ctx.fill();
    ctx.closePath;

    if (leftPressed && snekHead.x > 0) {
        snekHead.x -= snekHead.s;
    } else if (upPressed && snekHead.y > 0) {
        snekHead.y -= snekHead.s;
    } else if (rightPressed && snekHead.x < 500) {
        snekHead.x += snekHead.s;
    } else if (downPressed && snekHead.y < 500) {
        snekHead.y += snekHead.s;
    }
}

function draw() {
    ctx.clearRect(0, 0, ctx.width, ctx.height);
    // if (food.alive) {
    //     drawFood();
    // }
    drawSnek();
    // console.log("score: " + score);
    // if (Math.floor((Math.abs(snekHead.x - food.x))) <= 1 && Math.floor(Math.abs(snekHead.y - food.y) <= 1)) {
    //     foodEaten();
    // }
}

setInterval(draw, 60);
