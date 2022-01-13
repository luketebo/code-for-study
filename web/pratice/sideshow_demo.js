$(function () {
    var i = 0;           // 当前显示的图片索引
    var timer = null;    // 定时器
    var delay = 1000;    // 图片自动切换的间隔时间
    var width = 958;     // 每张图片的宽度
    var speed = 400;     // 动画时间
    // 复制列表中的第一个图片，追加到列表最后，设置ul的宽度为图片张数 * 图片宽度
    var firstimg = $('.hot li').first().clone();
    $('.hot').append(firstimg).width($('.hot li').length * width);
    // 1. 设置周期计时器，实现图片自动切换
    timer = setInterval(imgChange, delay);
    // 2. 鼠标移入，暂停自动播放，移出，开始自动播放
    $('.banner').hover(function () {
        clearInterval(timer);
    }, function () {
        timer = setInterval(imgChange, delay);
    });
    // 3. 鼠标划入圆点
    $('.dot li').mouseover(function () {
        i = $(this).index();
        $('.hot').stop().animate({ left: -i * width }, 200);
        dotChange();
    });
    // 4. 设置左右切换的箭头显示和隐藏
    $('.banner').hover(function () {
        $('.arrow').show();
    }, function () {
        $('.arrow').hide();
    });
    // 5. 向右箭头
    $('.next').click(function () {
        imgChange()
    });
    // 6. 向左箭头
    $('.prev').click(function () {
        --i;
        if (i == -1) {
            i = $('.hot li').length - 2;
            $('.hot').css({ left: -($('.hot li').length - 1) * width });
        }
        $('.hot').stop().animate({ left: -i * width }, speed);
        dotChange();
    });
    // 自动切换图片
    function imgChange() {
        ++i;
        isCrack();
        dotChange();
    }
    // 无缝轮播
    function isCrack() {
        if (i == $('.hot li').length) {
            i = 1;
            $('.hot').css({ left: 0 });
        }
        $('.hot').stop().animate({ left: -i * width }, speed);
    }
    // 自动切换对应的圆点
    function dotChange() {
        if (i == $('.hot li').length - 1) {
            $('.dot li').eq(0).addClass('on').siblings().removeClass('on');
        } else {
            $('.dot li').eq(i).addClass('on').siblings().removeClass('on');
        }
    }
});