let sticker;
let max;

function DP(start) {
    if(start >= sticker.length) {
        return 0;
    }
    if(max[start] !== undefined) {
        return max[start];
    }

    max[start] = Math.max((sticker[start] + DP(start + 2)), DP(start+1));
    return max[start];

}

function solution(sticker_) {
    sticker = sticker_;
    max = Array(sticker.length);
    let num = sticker_.length;

    while(num > 5000){
        DP(num-1);
        num -= 5000
    }
    return DP(0);
}


let sticker_ = [12,12,12,12,12];
for(let i = 0; i < 90000; ++i){
    sticker_.push(i);
}
console.log(solution(sticker_));