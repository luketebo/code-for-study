document.getElementById('next').onclick = function (param) {
    let lists = document.querySelectorAll('.item');
    document.getElementById('slide').appendChild(lists[0]);
}
document.getElementById('prev').onclick = function (param) {
    let lists = document.querySelectorAll('.item');
    document.getElementById('slide').prepend(lists[lists.length - 1])
}

document.onkeydown = f

function f(e) {
    // ArrowRight = 39 ArrowLeft = 37
    if (e.keyCode == 39) {
        let lists = document.querySelectorAll('.item');
        document.getElementById('slide').appendChild(lists[0]);
    } else if (e.keyCode == 37) {
        let lists = document.querySelectorAll('.item');
        document.getElementById('slide').prepend(lists[lists.length - 1]);
    }
}