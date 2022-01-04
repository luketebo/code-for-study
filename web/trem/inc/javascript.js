// 横栏的固定
// 小横条的动画
// 顶部的一些小动画
var bar = document.getElementById("fz");
console.log(bar);
// 我现在要获取fz目前所处的位置
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
  bg.animate({ "background-position-x": x + "%" }, 320, function () {
    bg.animate({ "background-position-x": 85 + "%" }, 320, polling());
  });
}
polling();
// 图片缩放
var mg = $("img");
console.log(mg);
$(function(){
  var w = $("img").width();
  var h = $("img").height();
  var w2 = w + 20;
  var h2 = h + 20;
  //stop 是jQuery中用于控制页面动画效果的方法。运行之后立刻结束当前页面上的动画效果。
  $("img").hover(function(){
    $(this).stop().animate({height:h2,width:w2,left:"-5px",top:"-5px"},400);
  },function(){
    $(this).stop().animate({height:h,width:w,left:"0",top:"0"},400);
  });
})

