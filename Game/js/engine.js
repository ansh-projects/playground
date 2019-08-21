/** An object that controls the game's mechanics */
var Engine = function() {
    /*  TODO */
    TODO('Make grid its own Graph Object that takes in a DOM in a new js file (like cell.js)');
    TODO('Grid DOM from div to canvas for performance');
    this.grid = document.createElement('div'), /** div that holds all the cells */
    this.game = {};     /** Game object that holds the games configurations */
    this.cells = [];    /** Cell array used as a Graph */ TODO("add to Graph object");

    /**
     * Recieves a click event from one of the three mode buttons in the main menu
     * and initializes the game based on that mode.
     * 
     * @param {Event} - Click event recieved from a mode button
     */
    this.start = function(event) {
        var infoID = event.target.id; /** ID of the button hit ( easyMode, mediumMode, or hardMode ) */
        var mode = infoID.substring(0, infoID.length - 4);
        switch (mode) {
            case 'easy':
            case 'medium':
            case 'hard':
                this.initGame(mode);
            break;
            
            default:
            break;
        }
    };

    /**
     * Initializes the game with the recieved mode
     * and then calls to initialize the grid.
     * 
     * @param {String} mode - "easy, medium, or hard"
     */
    this.initGame = function(mode) {
        this.game.mode = elems.modes[mode];
        elems.statusBar.title.classList.add("hide");
        elems.statusBar.resetBtn.classList.remove("hide");
        elems.statusBar.flagBtn.classList.remove("hide");
        this.initGrid()
    };

    /**
     * Initializes the grid based on the game configurations
     * and then calls to initialize the cells.
     */
    this.initGrid = function() {
        var rows = this.game.mode.rows;
        var cols = this.game.mode.cols;
        /** Hide main menu */
        elems.menu.style.display = 'none';

        this.grid.setAttribute("id", "gameboard");
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
        elems.container.appendChild(this.grid);
        
        this.initCells(rows, cols);
    };

    /**
     * Initializes the Cells based on the game configurations and current window display
     * 
     * @param {Number} rows - Number of rows for this game
     * @param {Number} cols - Number of cols for this game
     */
    this.initCells = function(rows, cols) {
        TODO("Account for grid gap")
        //var grid gap = 
        var padding = 50;
        var max_width = Math.floor( (elems.container.scrollWidth - padding) / cols ); // - grid gap
        var max_height = Math.floor( (elems.container.scrollHeight  - padding) / rows ); // - grid gap
        var length = Math.min(max_width, max_height);
        var cell_id = 0;
        /* TODO */
        TODO("get actual proximity");
        for(var row = 0; row < rows; row++){
            var cell_row = [];
            for(var col = 0; col < cols; col++){
                //
                var cell = document.createElement('div');
                cell.setAttribute("id", "cell" + cell_id);
                cell.style.width = length + 'px';
                cell.style.height = length + 'px';
                cell.setAttribute("class", "cell");
                this.grid.appendChild(cell);
                // proximity text TODO("probably remove from")
                var proximity = document.createElement('p');
                proximity.setAttribute("class", "proximityText");
                if( cell_id % 9 == 0 ){
                    proximity.innerHTML = ' ';
                } else {
                    // cell.setAttribute('class', 'snooped');
                    proximity.innerHTML = cell_id % 9;
                }
                proximity.style.lineHeight = length + 'px';
                cell.appendChild(proximity);
                
                initListener(cell, "click", handleCellClick);
                cell_id++;
                cell_row.push(new Cell(cell));
            }
            this.cells.push(cell_row);
        }
        this.initCellNeighbours();
    },

    /**
     * Initializes each cell's neighbour object
     */
    this.initCellNeighbours = function(){
        TODO("implement this")
    }
}