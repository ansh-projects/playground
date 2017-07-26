var x = 0;
var y = 0;
var xpos = 0;
var ypos = 0;

function setup() {
    createCanvas(400, 400);
    background(100, 100, 100);
}

function draw() {
    var scale = random(50);
    xpos = xdir(x) * scale;
    ypos = ydir(y) * scale;
    x = x + xpos;
    y = y + ypos;

    ellipse(x, y, 80, 80);
    console.log(x);
}

function xdir(x){
    if(x > width){
        return -1;
    } else if (x < -width) {
        return 1;
    } else {
        return x + 1;
    }
}

function ydir(y){
    if(y < 0){
        return -1;
    } else {
        return 1;
    }
}
