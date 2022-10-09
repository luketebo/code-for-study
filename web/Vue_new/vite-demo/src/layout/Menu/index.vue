<template>

    <div class="menu">
        菜单区域
        <Tree :data="data"></Tree>
    </div>


</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import Tree from '../../components/Tree/index.vue'

type TreeList = {
    name: string,
    icon?: string,
    children?: TreeList[] | []
}

const data = reactive<TreeList[]>([
    {
        name: "no.1",
        children: [
            {
                name: "no.1-1",
                children: [
                    {
                        name: "no.1-1-1"
                    }
                ]
            }
        ]
    }, {
        name: "no.2",
        children: [
            {
                name: "no.2-1"
            }
        ]
    }, {
        name: "no.3"
    }
])



</script>
<style scoped lang='less'>
.menu {
    width: 200px;
    border: 1px solid #ccc;
}
</style>