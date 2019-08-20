class Cell {
    constructor(height, width) {
        var texture;                     /* Texture for displaying the cell */
        var w;                           /* int for width        */
        var h;                           /* int for height       */
        var x;                           /* int for x position   */
        var y;                           /* int for y position   */
        var proximity;                   /* int for proximity    */
        var snooped;                     /* bool for if the Cell has been visited  */
        var is_bomb;                     /* bool for if the Cell is a bomb */
        var is_flag;                     /* bool for if the Cell is flagged */
        var neighbours = new Array[8];   /* Cell vector array for adjaent neighbours */
    };  
}/* Struct for a Cell */

var elems;

function loaded(){
    elems = {
        menu : document.getElementById('menu'),
        container : document.getElementById('container'),
        statusBar : {
            bombNums : document.getElementById('numBombs'),
            title    : document.getElementById('title'),
            resetBtn : document.getElementById('resetBtn'),
            moveNums : document.getElementById('numMoves'),
        },
        modes : {
            easy : {
                button: document.getElementById('easyModeBtn'),
                rows: 32,
                cols: 32,
                bombs: 17
            },
            medium : {
                button: document.getElementById('mediumModeBtn'),
                rows: 42,
                cols: 42,
                bombs: 21
            },
            hard : {
                button: document.getElementById('hardModeBtn'),
                rows: 64,
                cols: 64,
                bombs: 32
            }
        }
    }
    for(var mode in elems.modes){
        AttachEvent(elems.modes[mode].button, "click", start);
        AttachEvent(elems.modes[mode].button, "mouseover", handleModeButtonHover);
        AttachEvent(elems.modes[mode].button, "mouseleave", handleModeButtonUnHover);
    }  
    console.log("loaded");
    console.log(elems);
}

function start(e) {
    engine.start(e);
}

var engine = {
    canvas : document.createElement('canvas'),
    start : function(modeBtn) {
        this.canvas.setAttribute("id", "gameboard");
        this.canvas.width = elems.container.scrollWidth;
        this.canvas.height = elems.container.scrollHeight;
        this.context = this.canvas.getContext('2d');
        elems.menu.style.display = "none";
        elems.container.appendChild(this.canvas);
    }
}

function AttachEvent(element, type, handler) {
	if (element.addEventListener) {
        element.addEventListener(type, handler, false);
    } else {
        element.attachEvent("on"+type, handler);
    }
}

function handleModeButtonHover(event) {
    var target = event.target.innerHTML.toLowerCase();
    //todo make switch
    var bombs = elems.modes[target].bombs;
    this.children[0].classList.add("hide");
    this.children[1].classList.remove("hide");
    elems.statusBar.bombNums.children[0].innerHTML = bombs;
}

function handleModeButtonUnHover(event) {
    this.children[0].classList.remove("hide");
    this.children[1].classList.add("hide");
    elems.statusBar.bombNums.children[0].innerHTML = "&nbsp0";
}