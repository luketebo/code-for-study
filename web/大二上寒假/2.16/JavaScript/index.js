window.onload = function(){
    var change = document.getElementById("change");
    console.log(change);
    var times = 0;
    change.onclick = function(){
        console.log("demo");
        times++;
        if(times % 2 == 0){
            var center_1 = document.getElementsByClassName("center_1")[0];
            center_1.style.opacity = 1;
            var center_3 = document.getElementsByClassName("center_3")[0];
            center_3.style.opacity = 0;
            var center_2 = document.getElementsByClassName("center_2")[0];
            center_2.style.opacity = 1;
            var center_4 = document.getElementsByClassName("center_4")[0];
            center_4.style.opacity = 0;
        } else {
            var center_1 = document.getElementsByClassName("center_1")[0];
            center_1.style.opacity = 0;
            var center_3 = document.getElementsByClassName("center_3")[0];
            center_3.style.opacity = 1;
            var center_2 = document.getElementsByClassName("center_2")[0];
            center_2.style.opacity = 0;
            var center_4 = document.getElementsByClassName("center_4")[0];
            center_4.style.opacity = 1;
        }
        
    }
}