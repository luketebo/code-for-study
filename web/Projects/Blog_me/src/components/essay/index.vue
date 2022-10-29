<template>
    <div class="content">
        <div class="content-f">

            <div class="essay">
                <div class="essay-contain">
                    <header class="essay-contain-header">
                        <a class="essay-contain-header-nav"></a>
                        <div class="essay-contain-header-body">
                            <div>{{ title }}</div>
                            <div>{{ title_main }}</div>
                        </div>
                    </header>
                    <hr style="width: auto; margin: -2% 5%;" />
                    <main class="essay-contain-main">
                        <div class="essay-contain-main-title">目录</div>
                        <div class="essay-contain-main-main">
                            <ul>
                                <li><a @click="toPage('paper')" style="text-decoration: none"
                                        href="javascript: void(0)">1. demo</a></li>
                                <li><a>2. demo</a></li>
                                <li><a>3. demo</a></li>
                                <li><a>4. demo</a></li>
                                <li><a>5. demo</a></li>
                                <li><a>6. demo</a></li>
                            </ul>
                        </div>
                        <div class="essay-contain-main-footer">更新时间: 2022.10.27 22:58</div>
                    </main>
                </div>
            </div>
        </div>
    </div>
</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import { useRouter } from 'vue-router';


const title = ref("随笔")

const title_main = ref("简单记录一些东西，随便写写")

const router = useRouter()

const toPage = (name: string) => {
    console.log(name);

    router.push(name)
}

</script>
<style scoped lang='less'>
@border: #ccc;


.content {
    width: 80%;
    height: inherit;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;

    &-f {
        width: inherit;
        justify-content: center;
        align-items: center;
    }
}

.essay {
    width: 100%;
    height: 30vw;
    margin-top: 5%;
    border-radius: 3px;
    border: 1px solid @border;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;

    &-contain {
        border-radius: 5px;
        border: 1px solid @border;
        width: 65%;

        &-header {
            height: 5vw;
            width: auto;
            margin: 3% 5%;
            border: 1px solid @border;
            display: flex;
            // justify-content: center;
            align-items: center;

            &-nav {
                // padding: 0 5%;
                margin-right: 5%;
                height: 90%;
                width: 15%;
                border: 1px solid @border;
                background-image: url(../../assets/icon/renwuguanli.png);
                background-size: cover;
            }

            &-body {
                height: 90%;
                width: 100%;
                border: 1px solid @border;

                div:nth-child(1) {
                    font-size: 25px;
                }

                div:nth-child(2) {
                    margin: 2% 0;
                }
            }
        }

        &-main {
            height: 20vw;
            width: auto;
            margin: 3% 5%;
            border: 1px solid @border;
            display: flex;
            flex-direction: column;

            &-main {
                flex: 1;
                border: 1px solid @border;

                ul {
                    // flex: 1;
                    border: 1px solid @border;
                    height: auto;
                    display: flex;
                    flex-wrap: wrap;
                    flex-direction: row;
                    padding-left: 0;

                    li {
                        width: 50%;
                        height: 10%;
                        margin: 2% 0;
                    }
                }
            }

            &-title {
                font-size: 22px;
                margin: 2.5% 0;
            }

            &-footer {
                font-size: 14px;
                display: flex;
                justify-content: flex-end;
                margin-right: 3%;
            }
        }
    }

}
</style>
