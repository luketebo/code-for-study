<template>

 <div class="menu">
    菜单区域
    <div>
        {{title}}
    </div>
    <div>
        {{data}}
    </div>
    
 </div>
 

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'

// 接受父组件传递的值
type Props = {
    // 可选
    title?: string,
    data?: number[]
}

withDefaults(defineProps<Props>(), {
    title: "默认",
    // 特殊的数据，无法直接赋值，可以通过回调函数返回数据
    data: () => [1, 2, 3, 4]
})

</script>
<style scoped lang='less'>
.menu{
    width: 200px;
    border: 1px solid #ccc;
}
</style>