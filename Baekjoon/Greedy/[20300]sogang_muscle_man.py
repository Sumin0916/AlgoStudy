n = int(input())
muscle = list(map(int, input().split()))
muscle.sort()
m_loss = 0

if n % 2 == 0:
    for i in range(n//2):
        loss = muscle[i] + muscle[-(i+1)]
        if m_loss < loss:
            m_loss = loss
    print(m_loss)
else:
    n -= 1
    ls = muscle.pop()
    for i in range(n//2):
        loss = muscle[i] + muscle[-(i+1)]
        if m_loss < loss:
            m_loss = loss

    print(max(m_loss, ls))

