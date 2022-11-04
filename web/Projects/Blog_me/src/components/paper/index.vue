<template>

    <div class="paper">
        <div class="paper-left">
            <div class="paper-left-content">目录</div>
        </div>
        <div class="paper-center">
            <div class="paper-center-left"></div>
            <div class="paper-center-center">
                文章
            </div>
            <div class="paper-center-right">
                <el-affix :offset="120">
                    <div class="small-content">
                        <div>目录</div>
                        <hr/>
                        <div>内容</div>
                    </div>
                </el-affix>
            </div>
        </div>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive, } from 'vue'


</script>
<style scoped lang='less'>
@border: #ccc;

.paper {
    height: 100vw;
    width: 100%;
    // background-color: red;
    // padding: 0 13.9%;
    margin-right: 100%;
    border: 1px solid @border;
    display: flex;
    flex-direction: row;

    &-left {
        height: inherit;
        width: 14%;
        border: 1px solid @border;
        display: flex;
        justify-content: center;


        &-content {
            height: inherit;
            width: 100%;
            border: 1px solid @border;
        }
    }

    &-center {
        height: inherit;
        width: 86%;
        border: 1px solid @border;
        display: flex;
        flex-direction: row;
        margin-bottom: -2%;

        &-left {
            border: 1px solid @border;
            height: 100%;
            width: 18%;
            
        }

        &-center {
            border: 1px solid @border;
            height: inherit;
            width: 55%;
        }

        &-right {
            border: 1px solid @border;
            height: inherit;
            width: 10%;
            // display: flex;
            // justify-content: space-evenly;
        }

    }
}
.el-affix {
    width: 100%;
}

.small-content {
    border: 1px solid @border;
    width: 100%;
    height: auto;
    background-color: red;

}
</style>