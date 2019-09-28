function solution(goods, boxes){
    var answer = 0;
    goods.sort(compare);
    boxes.sort(compare);
    var gidx = 0, bidx = 0;
    for(;bidx < boxes.length;){
        if(goods[gidx] <= boxes[bidx]){
            answer++;
            gidx++;
            bidx++;
        }else{
            bidx++;
        }
    }
    return answer;
}

function compare ( a , b ) {   return a - b;   }

let participant = [200000000,200000000,7];
let completion = [3,20000000,200000000];
console.log(solution(participant, completion));