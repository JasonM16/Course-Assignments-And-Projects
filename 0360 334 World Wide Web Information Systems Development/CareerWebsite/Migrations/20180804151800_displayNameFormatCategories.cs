using Microsoft.EntityFrameworkCore.Migrations;

namespace CareerWebsite.Migrations
{
    public partial class displayNameFormatCategories : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Jobs_Locations_JobLocationId",
                table: "Jobs");

            migrationBuilder.AlterColumn<int>(
                name: "JobLocationId",
                table: "Jobs",
                nullable: false,
                oldClrType: typeof(int),
                oldNullable: true);

            migrationBuilder.AddForeignKey(
                name: "FK_Jobs_Locations_JobLocationId",
                table: "Jobs",
                column: "JobLocationId",
                principalTable: "Locations",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Jobs_Locations_JobLocationId",
                table: "Jobs");

            migrationBuilder.AlterColumn<int>(
                name: "JobLocationId",
                table: "Jobs",
                nullable: true,
                oldClrType: typeof(int));

            migrationBuilder.AddForeignKey(
                name: "FK_Jobs_Locations_JobLocationId",
                table: "Jobs",
                column: "JobLocationId",
                principalTable: "Locations",
                principalColumn: "Id",
                onDelete: ReferentialAction.Restrict);
        }
    }
}
