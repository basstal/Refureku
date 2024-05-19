import subprocess
import time

work_dir = "D:/Documents/GitHub/Sandbox/Plugins/refureku/Refureku/Refureku/Generator/ThirdParty/Kodgen"


def git_fetch_with_retry(retry_interval=5, max_attempts=10):
    """
    尝试执行`git fetch`操作，直到成功或达到最大尝试次数。

    :param retry_interval: 两次尝试之间的等待时间（秒）
    :param max_attempts: 最大尝试次数
    """
    attempt = 0
    while attempt < max_attempts:
        try:
            # 使用subprocess.run执行git fetch命令
            result = subprocess.run(
                ["git", "fetch"],
                check=True,
                cwd=work_dir,
            )
            print("git fetch操作成功。")
            break  # 如果成功，退出循环
        except subprocess.CalledProcessError as e:
            # 如果命令执行失败，打印错误信息并等待重试
            print(f"git fetch操作失败：{e}")
            attempt += 1
            print(f"正在重试...（尝试次数：{attempt}/{max_attempts}）")
            time.sleep(retry_interval)
    else:
        # 如果达到最大尝试次数，打印最终失败的消息
        print(f"git fetch操作在{max_attempts}次尝试后仍然失败。")


if __name__ == "__main__":
    git_fetch_with_retry()
