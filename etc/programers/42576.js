function solution(participant, completion) {
    participant.sort();
    completion.sort();
    let i = 0;
    for (i; i < completion.length; ++i) {
        if (participant[i] !== completion[i]) {
            break;
        }
    }
    return participant[i];
}

let participant = ["leo", "kiki", "eden"];
let completion = ["eden", "kiki"];
console.log(solution(participant, completion));