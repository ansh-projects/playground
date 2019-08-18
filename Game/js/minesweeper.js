var c = document.getElementById("mineField");
var ctx;

setInterval(function() {
    update();
    render();
}, 1000);

function update() {
    c.getAttribute('width') = window.innerWidth;
    c.getAttribute('height') = window.height;
    ctx = c.getContext("2d");
    ctx.moveTo(0, 0);
    ctx.lineTo(200, 100);
    ctx.stroke();
}

function render() {
    ctx.clearRect(0, 0, c.getAttribute('width'), c.getAttribute('height'))
}

