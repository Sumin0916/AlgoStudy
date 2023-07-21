### 스터디 일정

아래 일정은 강사 사정에 따라 변경될 수 있습니다.

|       | 날짜                | 내용                                                         |
| ----- | ------------------- | ------------------------------------------------------------ |
| 1차시 | 23.06.25 ~ 23.07.01 | Codeforces Polygon 사용법<br>[BOJ 28115 등차수열의 합](https://www.acmicpc.net/problem/28115) 지문, 제너레이터, 밸리데이터, 체커 작성 |
| 2차시 | 23.07.02 ~ 23.07.08 | [BOJ 28115 등차수열의 합](https://www.acmicpc.net/problem/28115) 피드백 반영<br>[BOJ 28119 Traveling SCCC President](https://www.acmicpc.net/problem/28119) 제너레이터, 밸리데이터 작성 |
| 3차시 | 23.07.09 ~ 23.07.15 | Prufer Sequence<br>[BOJ 22967 구름다리](https://www.acmicpc.net/problem/22967) 지문, 제너레이터, 밸리데이터, 체커 작성<br>[BOJ 21967 세워라 반석 위에](https://www.acmicpc.net/problem/21967) 제너레이터 작성 |
| 4차시 | 23.07.16 ~ 23.07.22 | 기하 데이터 제작 방법<br>[BOJ 19552 데이터 제작](https://www.acmicpc.net/problem/19552) 체커 작성 |
| 5차시 | 23.07.23 ~ 23.07.29 | [BOJ 25504 최적 경로와 쿼리](https://www.acmicpc.net/problem/25504) 제너레이터 작성<br>문제 아이디어 공모 및 출제 준비 |
| 6차시 | 23.07.30 ~ 23.08.12 | [BOJ 25504 최적 경로와 쿼리](https://www.acmicpc.net/problem/25504) 데이터 보강 |
| 7차시 | 23.08.13 ~ 23.08.26 | 문제 출제                                                    |

## Polygone 사용법

[한국어 폴리곤 사용법](https://evenharder.tistory.com/category/Polygon)  
[외국어 폴리곤 사용법](https://quangloc99.github.io/2022/03/08/polygon-codeforces-tutorial.html)  

## 트리 데이터 제작
트리가 주어지는 문제는 혹시 모를 코너케이스를 모두 잡기 위해서 $n$이 충분히 작은 모든 데이터를 넣는 것이 좋습니다. 정점이 $n$개인 labeled tree는 정확히 $n^{n-2}$개가 있습니다. prufer sequence를 이용하면 정점이 $n$개인 트리와 $n^{n-2}$ 이하의 자연수를 서로 변환할 수 있으니 데이터 제작할 때 참고하시길 바랍니다.  
[prufer sequence 설명](https://github.com/infossm/infossm.github.io/blob/master/_posts/2019-10-20-Pr%C3%BCfer-sequence.md)  
[prufer sequence 구현 연습](https://www.acmicpc.net/problem/20131) (설명 글과 다르게 L에서 번호가 가장 작은 정점이 아닌 가장 큰 정점을 뽑아야 합니다.)  
[O(n log n) 구현](https://github.com/justiceHui/icpc-teamnote/blob/master/code/Graph/PruferSequence.cpp)

## 기하 데이터 제작  

### 볼록 다각형
기하 문제를 만들 때 자주 만들게 되는 데이터로는 볼록 다각형과 공선점(일직선 상에 놓여있는 세 점)이 없는 2차원 점이 있습니다.  
볼록 다각형은 랜덤하게 점을 찍은 다음 convex hull을 구하면 될 것 같지만, 실제로 랜덤 데이터를 만들어 보면 볼록 다각형을 구성하는 점이 매우 적다는 것을 알 수 있습니다. 구체적으로 $X$ 좌표와 $Y$ 좌표의 범위가 $[1, C]$일 때, 볼록 다각형의 꼭짓점 개수의 기댓값은 $O(log C)$임을 보일 수 있습니다. [[참고링크]]( https://github.com/infossm/infossm.github.io/blob/master/_posts/2021-08-22-Expected_Complexity_of_Random_Convex_Hulls.md ) 따라서 랜덤 데이터만 사용해서는 좋은 데이터를 만들 수 없습니다.


먼저, $O(C^{1/2})$개의 점을 만드는 것은 꽤 간단합니다. 편의상 $[1, C] × [1, C]$ 영역을 4분할해서, 각 사분면에 사분원 비스무리한 것을 만든다고 합시다. 다음과 같은 코드를 통해 기울기가 $1, 2, 3, ...$ 인 변을 차례로 만들면 점이 $O(C^{1/2})$개 들어간 유사-사분원을 만들 수 있고, 4개를 이어 붙이면 좌표 범위가 10억일 때 약 12만 개 정도의 점을 만들 수 있습니다.

```C++
#include <bits/stdc++.h>
using namespace std;

int main(){
    int c = 1'000'000'000;
    vector<pair<int,int>> v;
    int x = 0, y = 0;
    for(int i=1; ; i++){
        x += 1; y += i;
        if(1 <= x && x <= c / 2 && 1 <= y && y <= c / 2) v.emplace_back(x, y);
        else break;
    }
    cout << v.size();
}
```

사실 볼록 다각형의 꼭짓점 개수 상한이 $O(C^{2/3})$임이 알려져 있습니다. [[참고링크]]( https://link.springer.com/article/10.1007/BF01216795 ) 따라서 $O(C^{2/3})$개의 점을 construct하는 방법을 알아내면 되는데, 이건 [여기](https://codeforces.com/blog/entry/62183?#comment-461811)에 잘 설명되어 있습니다.

주어진 점들이 실제로 볼록 다각형을 이루고 있는지 판별하는 것은 여러분들이 잘 알고 있는 볼록 껍질 알고리즘을 사용하면 됩니다. 볼록 껍질을 구하는 것은 $O(n log n)$보다 빠르게 할 수 없음을 증명할 수 있으니 안심하고 graham scan나 monotone chain을 사용하세요.

### 공선점(collinear points) 없는 데이터
데이터 생성을 설명하기 전에, 데이터 검증에 대해 먼저 이야기하겠습니다. 2차원 평면 위에 $N$개의 점이 주어졌을 때 한 직선 위에 놓인 세 점이 있는지 판별하는 것은 $O(N^{2-\epsilon})$보다 빠르게 하는 방법이 아직까지 알려지지 않았습니다. [[링크]](https://github.com/infossm/infossm.github.io/blob/master/_posts/2023-03-19-3sum-conjecture.md) 따라서 점이 10만 개 이상이라면 polygon validator에서 확인하는 대신, 로컬에서 돌리는 방법을 주로 사용합니다.

$O(N^3)$이 돌아갈 정도의 범위에서는 단순히 점을 랜덤으로 생성한 다음, 기존에 만든 점 집합에 추가했을 때 모순이 안 생기는지 확인하는 것으로 충분합니다. 그 이상이 문제인데, 이럴 때는 보통 애드혹하게 점을 생성하는 편입니다.

볼록 다각형에는 평행한 세 점이 없다는 점을 이용해 위에서 언급한 방법을 이용해 볼록 다각형을 생성하는 것도 한 가지 방법이지만, 좌표 범위가 작을 때는 사용하기 어렵다는 단점이 있습니다.

가장 자주 사용하는 방법은 $(x, x^2)$를 찍는 건데, 이건 $x^2$이 너무 커진다는 단점이 있습니다. 이 문제를 해결하는 가장 간단한 방법은 $x^2$를 적당한 소수 $P$로 나눈 나머지를 취하는 것입니다. 생성해야 하는 점의 개수를 $N$, 좌표 범위를 $C$라고 했을 때, $N < P < C$인 $P$를 잡은 다음 $(1, 1^2 \pmod P)$부터 $(N, N^2 \pmod P)$까지 찍으면 공선점이 없음을 증명할 수 있습니다.

이 두 가지 방법을 사용하면 공선점이 없는 데이터도 잘 만들 수 있습니다.

### 기타

* 이 스터디는 [**현대모비스**](https://www.mobis.co.kr/kr/index.do)의 우수 SW 동아리 지원을 받아 진행되었습니다.
* 등차수열의 합 문제의 저작권은 [kyo20111](https://www.acmicpc.net/user/kyo20111), 다른 모든 문제의 저작권은 [jhnah917](https://www.acmicpc.net/user/jhnah917)에게 있습니다.
