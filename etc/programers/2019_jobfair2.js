function make_chessboard(){
    let board = new Set();

    for(let i = 0; i < 8; ++i){
        for(let j = 0; j< 8; ++j){
    board.add(""+i+j);
        }
    }
    return board;
}
function check(e,board){
    let i = e.charCodeAt(0) - 48;
    let j = e.charCodeAt(1) - 48;
    let tmpi = i;
    let tmpj = j;
    while(tmpi >= 0 && tmpj >= 0 && tmpi <= 7 && tmpj <= 7){
        board.delete(""+tmpi+tmpj);
        tmpi--;
        tmpj--;
    }
    tmpi = i;
    tmpj = j;
    while(tmpi >= 0 && tmpj >= 0 && tmpi <= 7 && tmpj <= 7){
        board.delete(""+tmpi+tmpj);
        tmpi++;
        tmpj--;
    }
    tmpi = i;
    tmpj = j;
    while(tmpi >= 0 && tmpj >= 0 && tmpi <= 7 && tmpj <= 7){
        board.delete(""+tmpi+tmpj);
        tmpi--;
        tmpj++;
    }
    tmpi = i;
    tmpj = j;
    while(tmpi >= 0 && tmpj >= 0 && tmpi <= 7 && tmpj <= 7){
        board.delete(""+tmpi+tmpj);
        tmpi++;
        tmpj++;
    }
}

function solution(bishops) {
    let board = make_chessboard();
    for (let i = 0; i < bishops.length; ++i) {
        bishops[i] = "" + (bishops[i].charCodeAt(0) - 65) + (bishops[i].charCodeAt(1) - 49);
    }
    bishops.forEach(e => {check(e,board)});
    return board.size;
}

