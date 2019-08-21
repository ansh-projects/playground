window.onbeforeunload = function(event) {
    return "Progress will be lost."
}

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
    //init elems
    elems = {
        menu : document.getElementById('menu'),
        container : document.getElementById('container'),
        statusBar : {
            bombNums : document.getElementById('numBombs'),
            title    : document.getElementById('title'),
            resetBtn : document.getElementById('resetBtn'),
            flagBtn  : document.getElementById('flagBtn'),
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
    //init events
    for(var mode in elems.modes){
        AttachEvent(elems.modes[mode].button, "click", start);
        AttachEvent(elems.modes[mode].button, "mouseover", handleModeButtonHover);
        AttachEvent(elems.modes[mode].button, "mouseleave", handleModeButtonUnHover);
    }  
    console.log("Page Elements Loaded");
}

function start(e) {
    engine.start(e);
}

var engine = {
    grid : document.createElement('div'),

    game : {},
    
    start : function(event) {
        this.initGame(event);
    },

    initGame : function(event) {
        var infoID = event.target.id;
        var mode = infoID.substring(0, infoID.length - 4);
        switch (mode) {
            case 'easy':
            case 'medium':
            case 'hard':
                this.game.mode = elems.modes[mode];
                break;
            default:
                break;
        }
        elems.statusBar.title.classList.add("hide");
        elems.statusBar.resetBtn.classList.remove("hide");
        elems.statusBar.flagBtn.classList.remove("hide");
        this.initGrid()
    },

    initGrid : function() {
        var rows = this.game.mode.rows;
        var cols = this.game.mode.cols;
        elems.menu.style.display = 'none';
        this.grid.setAttribute("id", "gameboard");
        elems.container.appendChild(this.grid);
        var gridTemplateColumns = '';
        var gridTemplateRows = '';
        for(var i = 0; i < cols; i++){
            gridTemplateColumns += 'auto ';
        }
        var gridTemplateRows = '';
        for(var i = 0; i < rows; i++){
            gridTemplateRows += 'auto ';
        }
        this.grid.style.gridTemplateColumns = gridTemplateColumns;
        this.grid.style.gridTemplateRows = gridTemplateRows;
        this.initCells(rows, cols);
    },

    initCells : function(rows, cols) {
        var cell_id = 0;
        for(var row = 0; row < rows; row++){
            for(var col = 0; col < cols; col++){
                var cell = document.createElement('div');
                cell.setAttribute("class", "cell");
                this.grid.appendChild(cell);
            }
        }
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
    var mode = event.target.innerHTML.toLowerCase();
    var bombs = elems.statusBar.bombNums.children[0].innerHTML;

    switch (mode) {
        case 'easy':
        case 'medium':
        case 'hard':
            var game_mode = elems.modes[mode];
            bombs = game_mode.bombs;
            this.children[1].innerHTML = game_mode.rows + " × " + game_mode.cols;
            break;
    
        default:
            break;
    }

    this.children[0].classList.add("hide");
    this.children[1].classList.remove("hide");
    elems.statusBar.bombNums.children[0].innerHTML = bombs;
}

function handleModeButtonUnHover(event) {
    this.children[0].classList.remove("hide");
    this.children[1].classList.add("hide");
    elems.statusBar.bombNums.children[0].innerHTML = "&nbsp0";
}