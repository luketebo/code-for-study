// 实现图片无缝切换
$(function () {
  var width = 958;
  var firstimg = $(".hot li").first().clone();
  $(".hot")
    .append(firstimg)
    .width($(".hot li").length * width);
});
// 实现图片自动切换
var timer = null;
var dalay = 1000;
timer = setInterval(img_change, dalay);
var i = 0;
function img_change() {
  ++i;
  isCrack();
  dotChange();
}
var speed = 400;
var width = 958;
function isCrack() {
  if (i == $(".hot li").length) {
    i = 1;
    $(".hot li").css({ left: 0 });
  }
  $(".hot")
    .stop()
    .animate({ left: -i * width }, speed);
}
function dotChange() {
  if (i == $(".hot li").length - 1) {
    $(".hot li").eq(0).addClass("on").siblings().removeClass("on");
  } else {
    $(".hot li").eq(i).addClass("on").siblings().removeClass("on");
  }
}
$(".banner").hover(
  function () {
    clearInterval(timer);
  },
  function () {
    timer = setInterval(img_change, dalay);
  }
);
// 鼠标滑过圆点
$(".dot li").mouseover(function () {
  i = $(this).index();
  $(".hot")
    .stop()
    .animate({ left: -i * width }, 200);
  dotChange();
});
// 利用箭头左右切换
$(".banner").hover(
  function () {
    $(".arrow").show();
  },
  function () {
    $("arrow").hide();
  }
);
$(".next").click(function () {
  img_change();
});
$(".prev").click(function () {
  i--;
  if (i == -1) {
    i = $(".hot li").length - 2;
    $(".hot").css({ left: -($(".hot li").lenth - 1) * width });
  }
  $(".hot")
    .stop()
    .animate({ left: -i * width }, speed);
  dotChange();
});
