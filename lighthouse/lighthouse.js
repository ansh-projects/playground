const GRID = [
    ["", "", "", "^", "", "", "", "", "", ""],
    ["", "", "v", "", "~", "", "", "", "", ""],
    ["", "v", "", "", "^", "^", "", "", "", ""],
    ["", "", "", "", "^", "^", "", "", "", ""],
    ["", "", "", "", "", "", "", "", "v", ""],
    ["", "", "", "", "", "", "", "", "", ""],
    ["", "", "", "", "", "", "", "", "", ""],
    ["", "^", "~", "~", "", "", "", "^", "", ""],
    ["", "^", "", "~", "~", "", "", "", "", ""],
    ["", "^", "", "", "~", "~", "", "", "", ""],
  ];

function countRows(){
	return GRID.length;
}

function countColumns(){
	return GRID[0].length;
}

function gridSize(){
	return countColumns() + ' x ' + countRows();
}

function totalCells(){
	return countRows()*countColumns();
}

function convertColumn(coordinate){
	//if letter
	if(coordinate[0].match(/[a-z]/i)){
		//A char code is 65
		return coordinate.toUpperCase().charCodeAt(0)-65;
	}
	//error
	return -1;
}

function lightCell(coordinate){
	var col = convertColumn(coordinate);
	var row = coordinate.slice(1)-1;
	if(isCellValid(row, col)){
		return GRID[row][col];
	}
	return false;
}

function isRock(coordinate){
	return lightCell(coordinate) === '^';
}
  
function isCurrent(coordinate){
	return lightCell(coordinate) === '~';
}

function isShip(coordinate){
	return lightCell(coordinate) === 'v';
}

function lightRow(row){
	if(row > 0 && row <= countRows()){
		return GRID[row-1]
	}
	return -1;
}

function lightColumn(column){
	column = convertColumn(column+""+1);
	if(column >= 0 && column < countColumns()){
		var colItems = [];
		for(var i = 0; i < countRows(); i++){
			colItems.push(GRID[i][column])
		}
		return colItems;
	}
	return -1;
} 

function isCellValid(row, col){
	if ((row >= 0 && row < countRows())&&(col >= 0 && col < countColumns())){
		return true;
	}
	return false;
}

function allRocks(){
    var rocks = [];
    for(var row = 0; row < countRows(); row++){
        for(var col = 0; col < countColumns(); col++){
            if(GRID[row][col] === '^'){
                rocks.push(String.fromCharCode(97+col).toUpperCase()+""+(row+1))
            }
        }
    }
    return(rocks);
}

function allCurrents(){
    var currents = [];
    for(var row = 0; row < countRows(); row++){
        for(var col = 0; col < countColumns(); col++){
            if(GRID[row][col] === '~'){
                currents.push(String.fromCharCode(97+col).toUpperCase()+""+(row+1))
            }
        }
    }
    return(currents);
}

// allRocks();