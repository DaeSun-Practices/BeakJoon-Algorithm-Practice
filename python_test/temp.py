class Tree:
    """
    트리의 현재 상태를 나타내는 클래스
    """
    def __init__(self, current_leaf_num, used_dist, current_product):
        self.current_leaf_num = current_leaf_num  # 현재 레벨의 노드 개수
        self.used_dist = used_dist                # 지금까지 사용한 분배 노드 개수
        self.current_product = current_product    # 루트부터 현재까지의 자식 수 곱 (분배도)
    
    def get_key(self):
        """메모이제이션을 위한 키 생성"""
        return (self.current_leaf_num, self.used_dist, self.current_product)


# 메모이제이션을 위한 딕셔너리
memo = {}

def dfs(tree, dist_limit, split_limit):
    """
    DFS로 최대 리프 노드 수를 계산
    
    Args:
        tree: Tree 객체 (현재 상태)
        dist_limit: 최대 분배 노드 개수
        split_limit: 리프 노드의 최대 분배도
    
    Returns:
        이 상태에서 만들 수 있는 최대 리프 수
    """
    # 노드가 없으면 리프도 0개
    if tree.current_leaf_num == 0:
        return 0
    
    # 이미 계산한 상태면 저장된 값 반환
    key = tree.get_key()
    if key in memo:
        return memo[key]
    
    # 옵션 1: 현재 레벨의 모든 노드를 리프로 만들기
    # 이게 기본 답이고, 여기서 더 좋은 방법을 찾으면 갱신
    max_leaves = tree.current_leaf_num
    
    # 옵션 2: k개의 노드를 선택해서 분배 노드로 확장하기
    # 나머지는 리프로 남김
    for k in range(1, tree.current_leaf_num + 1):
        # 각 분배 노드는 2개 또는 3개의 자식을 가질 수 있음
        for child_count in [2, 3]:
            # 분배 노드 개수 제약 확인
            new_dist = tree.used_dist + k
            if new_dist > dist_limit:
                continue
            
            # 분배도 제약 확인
            # 다음 레벨의 분배도는 현재 분배도 * 자식 개수
            new_product = tree.current_product * child_count
            if new_product > split_limit:
                continue
            
            # k개를 확장하면:
            # - 리프로 남는 노드: current_leaf_num - k
            # - 다음 레벨의 노드: k * child_count
            leaves_at_this_level = tree.current_leaf_num - k
            next_level_nodes = k * child_count
            
            # 다음 레벨의 상태를 나타내는 새로운 Tree 객체 생성
            next_tree = Tree(next_level_nodes, new_dist, new_product)
            
            # 다음 레벨에서 얻을 수 있는 최대 리프 수를 재귀로 계산
            leaves_from_next_level = dfs(next_tree, dist_limit, split_limit)
            
            # 현재 레벨의 리프 + 다음 레벨의 리프 = 총 리프 수
            max_leaves = max(max_leaves, leaves_at_this_level + leaves_from_next_level)
    
    # 계산 결과를 저장하고 반환
    memo[key] = max_leaves
    return max_leaves


def solve(dist_limit, split_limit):
    """
    주어진 제약 조건 하에서 만들 수 있는 트리의 최대 리프 노드 수를 계산
    
    Args:
        dist_limit: 최대 분배 노드 개수
        split_limit: 리프 노드의 최대 분배도
    
    Returns:
        최대 리프 노드 수
    """
    # 메모 초기화
    memo.clear()
    
    # 분배 노드를 하나도 사용할 수 없는 경우
    if dist_limit == 0:
        return 1
    
    # 루트의 자식 1개부터 시작
    # 루트는 분배 노드가 아니므로 used_dist = 0
    # 루트의 자식 수는 1이므로 current_product = 1
    initial_tree = Tree(
        current_leaf_num=1,
        used_dist=0,
        current_product=1
    )
    
    return dfs(initial_tree, dist_limit, split_limit)


# 메인 실행
if __name__ == "__main__":
    # 입력 받기
    dist_limit, split_limit = map(int, input().split())
    
    # 답 계산 및 출력
    answer = solve(dist_limit, split_limit)
    print(answer)
    
    # 테스트 케이스 실행 (주석 처리)
    
    print("=== 테스트 케이스 ===\n")
    
    test_cases = [
        (3, 6, 6),
        (0, 10, 1),
        (3, 100, 7),
        (5, 16, 9)
    ]
    
    for dist, split, expected in test_cases:
        result = solve(dist, split)
        passed = "✓" if result == expected else "✗"
        print(f"dist_limit={dist}, split_limit={split}")
        print(f"결과: {result}, 예상: {expected} {passed}\n")
    