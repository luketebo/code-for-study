// 横栏的固定
// 顶部的一些小动画
var bar = document.getElementById("fz");
// 我没有找到fz
console.log(bar);
console.log(bar.offsetHeight, bar.offsetWidth);

$(function () {
  var navH = $("#fz").offset().top;
  //滚动事件
  $(window).scroll(function () {
    //获取滚动条的滑动距离
    var scroH = $(this).scrollTop();
    if (scroH >= navH) {
      $("#fz").css({ position: "fixed", top: 0, left: 0 });
    } else if (scroH < navH) {
      $("#fz").css({ position: "static", margin: "0,auto" });
    }
    console.log(scroH == navH);
  });
});
var bg = $(".qsong");
console.log(bg);
var x = 80;
function polling() {
  bg.animate({"background-position-x":x+"%"},320,function(){
  bg.animate({"background-position-x":85+"%"},320,polling());
  })
}
polling();